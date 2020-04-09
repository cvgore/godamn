#include "Engine.h"

namespace Godamn
{
	constexpr char FF_MAIN_FONT[] = "assets/tradewinds.ttf";
	constexpr char FF_ALT_FONT[] = "assets/roboto.ttf";
	constexpr char FF_TILESET[] = "assets/tiles.png";

	/**
	 * This files are required for game to launch
	 */
	const char* requirements[] = {
		FF_ALT_FONT, FF_MAIN_FONT, FF_TILESET
	};

	Engine::Engine()
	{
		this->m_renderer = NULL;
		this->m_state = NULL;
	}

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
		if (!this->m_mainFont.loadFromFile(FF_MAIN_FONT))
		{
			PANIC("Could not find tradewinds font");
		}

		if (!this->m_mainFont.loadFromFile(FF_ALT_FONT))
		{
			PANIC("Could not find roboto font");
		}

		this->m_renderer = new sf::RenderWindow(
			sf::VideoMode(800, 600),
			APP_NAME " " APP_VERSION,
			sf::Style::Default ^ sf::Style::Resize
		);
	}

	int Engine::spawn()
	{
		DEBUG("Creating renderer...");

		this->m_state = new Godamn::GameState(*this->m_renderer);

		std::vector<uint8_t> cfg {};
		
		for (uint16_t i = 0; i < (24 * 15); i++)
		{
			cfg.push_back(i % 2);
		}
		
		this->m_state->getMap()->loadTileset(FF_TILESET, sf::Vector2<uint8_t>(32, 32));
		this->m_state->getMap()->setRenderSize(sf::Vector2<uint8_t>(24, 15));
		// this->m_state->getMap()->setTilesConfig(cfg);
		this->m_state->getMap()->setPosition(16.f, 16.f);
		
		this->m_state->setPosition(0.f, 700.f);

		DEBUG("Creating game instance...");

		while (this->m_renderer->isOpen())
		{
			sf::Event event;

			while (this->m_renderer->pollEvent(event))
			{
				this->m_state->handleEvent(event);
			}

			this->m_renderer->clear(sf::Color::Black);

			this->m_renderer->draw(*this->m_state);

			this->m_renderer->display();
		}

		DEBUG("Bye bye...");

		return 0;
	}
}
