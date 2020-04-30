#include "Engine.h"
#include "Events/Event.h"
#include "Utils.h"

using EventType = sf::Event::EventType;

namespace Godamn
{
	constexpr char FF_MAIN_FONT[] = "assets/fonts/tradewinds.ttf";
	constexpr char FF_ALT_FONT[] = "assets/fonts/roboto.ttf";
	constexpr char FF_TILESET[] = "assets/tiles.png";

	/**
	 * This files are required for game to launch
	 */
	const char* requirements[] = {
		FF_ALT_FONT, FF_MAIN_FONT, FF_TILESET
	};

	Engine::Engine(): m_renderer(nullptr), m_state(nullptr), m_map(nullptr)
	{
	}

	Engine::~Engine()
	{
		for (auto& entity : m_entities)
		{
			entity.reset();
		}

		m_renderer.reset();
		
		delete m_state;
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
				PANIC("Could not stat on file")
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
			sf::VideoMode(800, 600),
			APP_NAME " " APP_VERSION,
			sf::Style::Default ^ sf::Style::Resize
		));
	}

	int Engine::spawn()
	{
		m_state = __new GameState;

		auto tiledMapRect = sf::FloatRect(16.f, 16.f, 768.f, 480.f);

		m_map = std::shared_ptr<TiledMap>(__new TiledMap(tiledMapRect));

		m_entities.push_back(m_map);

		m_map->loadTileset(FF_TILESET, sf::Vector2<uint8_t>(32, 32));
		m_map->setRenderSize(sf::Vector2<uint8_t>(24, 15));

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

			m_renderer->clear(sf::Color::Black);
			m_renderer->draw(*this);
			m_renderer->display();
		}

		return 0;
	}

	std::shared_ptr<TiledMap> Engine::getMap() const
	{
		return m_map;
	}

	void Engine::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		m_map->updateIfOutdated();

		for (const auto& entity : m_entities)
		{
			target.draw(*entity);
		}
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

		for (auto& entity : m_entities)
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
}
