#include "Engine.h"
#include "Entities/Hud.h"
#include "Events/Event.h"
#include "Foundation/Container.h"
#include "MapGenerator/Generator.h"
#include "Scenery/SceneryManager.h"
#include "Utils/Crypto.h"
#include "Utils/Utils.h"

using EventType = sf::Event::EventType;

namespace Godamn
{
	constexpr uint32_t TIMER_INTERVAL_MIN = 100;

	constexpr char FF_MAIN_FONT[] = "assets/fonts/tradewinds.ttf";
	constexpr char FF_ALT_FONT[] = "assets/fonts/roboto.ttf";
	constexpr char FF_TILESET[] = "assets/Graphics/Mix.png";

	/**
	 * This files are required for game to launch
	 */
	const char* requirements[] = { FF_ALT_FONT, FF_MAIN_FONT, FF_TILESET };

	Engine::Engine(): m_renderer(nullptr), m_threadPool(nullptr)
	{}

	Engine::~Engine()
	{
		m_renderer.reset();
	}

	/**
	 * @brief Checks for existence of required files in FF_* and requirements constant
	 */
	void Engine::runChecks()
	{
		struct stat data;

		for (const auto* requirement : requirements)
		{
			if (stat(requirement, &data) != EXIT_SUCCESS)
			{
				PANIC("Could not stat on file: %s", requirement);
			}
		}
	}

	void Engine::initialize()
	{
		// TODO: load from memory assets
		if (!m_mainFont.loadFromFile(FF_MAIN_FONT))
		{
			PANIC("Could not find tradewinds font");
		}

		if (!m_mainFont.loadFromFile(FF_ALT_FONT))
		{
			PANIC("Could not find roboto font");
		}

		m_renderer = std::shared_ptr<sf::RenderWindow>(__new sf::RenderWindow(
		sf::VideoMode(800, 600), APP_NAME " " APP_VERSION, sf::Style::Default ^ sf::Style::Resize,
		sf::ContextSettings(0, 0, 2)));

		m_threadPool = CreateThreadpool(nullptr);

		SetThreadpoolThreadMaximum(m_threadPool, 2);
		SetThreadpoolThreadMinimum(m_threadPool, 1);

		FILETIME ft = { 0, 0 };

		m_timer = CreateThreadpoolTimer(timerCallback, nullptr, nullptr);
		SetThreadpoolTimerEx(m_timer, &ft, TIMER_INTERVAL_MIN, TIMER_INTERVAL_MIN / 10);

		m_renderer->setFramerateLimit(60);

		// https://stackoverflow.com/questions/17888993/key-repetition-in-sfml-2-0
		m_renderer->setKeyRepeatEnabled(false);
	}

	int Engine::spawn()
	{
		auto tiledMapRect = sf::FloatRect(16.f, 16.f, 768.f, 480.f);

		auto manager = getContainer().getSceneryManager().get();
		auto& scenePtr = manager->newScene();
		auto scene = scenePtr.get();

		manager->setActiveScene(scenePtr);

		scene->addEntity(__new TiledMap(tiledMapRect));

		auto& mapEnt = *scene->findEntityByGuid(TiledMap::getEntityId());
		auto map = static_cast<TiledMap*>(mapEnt.get());

		auto tilesArray = Generator::generator();

		map->loadTileset(FF_TILESET, { 32, 32 });
		map->setRenderSize({ 24, 15 });
		map->setTilesConfig(tilesArray);
		map->unveilBase();

		scene->addEntity(
		__new Hud({ 16.f, getGeometry().height - 100.f + 8.f, getGeometry().width - 32.f, 100.f - 16.f - 8.f }));

		while (m_renderer->isOpen())
		{
			sf::Event event;

			while (m_renderer->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					m_renderer->close();
				}

				propagateEvent(event);
			}

			auto& activeScene = *getContainer().getSceneryManager()->getActiveScene();

			m_renderer->clear(sf::Color::Black);

			beforeDraw(activeScene);
			m_renderer->draw(activeScene);
			afterDraw(activeScene);

			m_renderer->display();
		}

		CloseThreadpoolTimer(m_timer);
		m_timer = nullptr;
		CloseThreadpool(m_threadPool);
		m_threadPool = nullptr;

		return 0;
	}

	sf::Vector2f Engine::translateEventPosition(const sf::Event& event)
	{
		sf::Vector2f vec;

		switch (event.type)
		{
			case EventType::MouseButtonReleased:
			case EventType::MouseButtonPressed:
				vec.x = static_cast<float>(event.mouseButton.x);
				vec.y = static_cast<float>(event.mouseButton.y);
				break;
			case EventType::MouseMoved:
				vec.x = static_cast<float>(event.mouseMove.x);
				vec.y = static_cast<float>(event.mouseMove.y);
				break;
			case EventType::MouseWheelScrolled:
				vec.x = static_cast<float>(event.mouseWheelScroll.x);
				vec.y = static_cast<float>(event.mouseWheelScroll.y);
				break;
		}

		return vec;
	}

	void Engine::propagateEvent(const sf::Event& event)
	{
		sf::Vector2f pos = translateEventPosition(event);

		Event wrapper(event, pos);

		for (auto& entity : *getContainer().getSceneryManager()->getActiveScene())
		{
			if (wrapper.isMouseEvent())
			{
				if (entity->getRect().contains(pos))
				{
					entity->onEvent(wrapper);
				}
			}
			else
			{
				entity->onEvent(wrapper);
			}
		}
	}

	const sf::FloatRect Engine::getGeometry() const
	{
		auto size = getRenderWindow().getSize();

		return { 0.f, 0.f, static_cast<float>(size.x), static_cast<float>(size.y) };
	}

	const sf::RenderWindow& Engine::getRenderWindow() const
	{
		return *m_renderer;
	}

	void Engine::timerCallback(PTP_CALLBACK_INSTANCE hInst, PVOID ctx, PTP_TIMER timer)
	{
		static std::vector<TimerMap::key_type> timersToRemove;
		auto engine = getContainer().getEngine();
		auto& callbacks = engine->m_timerCallbacks;

		for (auto& data : callbacks)
		{
			auto [id, callbackData] = data;
			auto [lastCalled, interval, callback] = callbackData;

			const auto now = getCurrentTimestamp();

			if ((lastCalled + interval) <= now)
			{
				std::get<0>(data.second) = getCurrentTimestamp();

				callback(now - lastCalled, [id = data.first]() -> void {
					DEBUG("Scheduling deletion of timer %lld", id);
					timersToRemove.emplace_back(id);
				});
			}
		}

		if (timersToRemove.size() > 0)
		{
			for (const auto& key : timersToRemove)
			{
				DEBUG("Removing timer %lld", key);
				callbacks.erase(key);
			}

			timersToRemove.clear();
		}
	}

	uint64_t Engine::getCurrentTimestamp()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(
			   std::chrono::steady_clock::now().time_since_epoch())
		.count();
	}

	uint64_t Engine::listenTimer(uint32_t interval, Engine::TimerCallback callback)
	{
		const auto id = Crypto::getRandomNumber();

		m_timerCallbacks.emplace(id, TimerTuple(getCurrentTimestamp(), interval, callback));

		return id;
	}

	const sf::Font& Engine::getMainFont() const
	{
		return m_mainFont;
	}
}
