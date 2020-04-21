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

	Engine::Engine(): m_renderer(NULL), m_state(NULL), m_map(NULL)
	{
	}

	Engine::~Engine()
	{
		for (Entity* entity : this->m_entities)
		{
			delete entity;
		}
		
		delete this->m_state;
		delete this->m_renderer;
	}

	/**
	 * @brief Checks for existence of required files in FF_* and requirements constant
	 */
	void Engine::runChecks()
	{
		struct stat data;

		for (auto requirement : requirements)
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
		if (!this->m_mainFont.loadFromFile(FF_MAIN_FONT))
		{
			PANIC("Could not find tradewinds font");
		}

		if (!this->m_mainFont.loadFromFile(FF_ALT_FONT))
		{
			PANIC("Could not find roboto font");
		}
		
		this->m_renderer = __new sf::RenderWindow(
			sf::VideoMode(800, 600),
			APP_NAME " " APP_VERSION,
			sf::Style::Default ^ sf::Style::Resize
		);
	}

	int Engine::spawn()
	{
		this->m_state = __new GameState;

		auto tiledMapRect = sf::FloatRect(16.f, 16.f, 768.f, 480.f);
		
		this->m_map = __new TiledMap(tiledMapRect);

		this->m_entities.push_back(this->m_map);

		// std::vector<uint8_t> cfg {};
		//
		// for (uint16_t i = 0; i < (24 * 15); i++)
		// {
		// 	cfg.push_back(i % 2);
		// }

		this->m_map->loadTileset(FF_TILESET, sf::Vector2<uint8_t>(32, 32));
		this->m_map->setRenderSize(sf::Vector2<uint8_t>(24, 15));
		// this->m_map->setTilesConfig(cfg);

		while (this->m_renderer->isOpen())
		{
			sf::Event event;

			while (this->m_renderer->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					this->m_renderer->close();
				}

				this->propagateEvent(event);
			}

			this->m_renderer->clear(sf::Color::Black);

			this->m_renderer->draw(*this);

			this->m_renderer->display();
		}

		DEBUG("Bye bye...");

		return 0;
	}

	TiledMap* Engine::getMap() const
	{
		return this->m_map;
	}

	void Engine::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		this->m_map->updateIfOutdated();

		for (Entity* const entity : this->m_entities)
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
		sf::Vector2f pos = this->translateEventPosition(event);

		Godamn::Event wrapper(*this, event, pos);

		for (Entity* entity : this->m_entities)
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
