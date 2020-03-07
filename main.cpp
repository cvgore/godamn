#include "main.h"

int main()
{
	sf::Font mainFont;
	if (!mainFont.loadFromFile("assets/tradewinds.ttf"))
	{
		LOG_DEBUG("Could not find tradewinds font");
		return 0;
	}

	sf::Font textFont;
	if (!textFont.loadFromFile("assets/roboto.ttf"))
	{
		LOG_DEBUG("Could not find roboto font");
		return 0;
	}

	LOG_DEBUG("Creating renderer...");

	sf::RenderWindow window(
		sf::VideoMode(800, 600),
		APP_NAME " " APP_VERSION,
		sf::Style::Default ^ sf::Style::Resize
	);

	Godamn::TiledMap map {};
	Godamn::Player player("Player");
	Godamn::GameState gameState(player);

	std::vector<uint8_t> cfg {0, 1, 0, 1};

	map.loadTileset("assets/tiles.png", sf::Vector2<uint8_t>(32, 32));
	map.setRenderSize(sf::Vector2<uint8_t>(4, 1));
	map.setTilesConfig(cfg);
	map.setPosition(10.f, 10.f);

	LOG_DEBUG("Creating game instance...");

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::L)
			{
				std::vector<uint8_t> cfg {1, 0, 0, 0};
				map.setTilesConfig(cfg);
			}

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		map.updateIfOutdated();
		window.draw(map);
		window.draw(gameState);

		window.display();
	}

	LOG_DEBUG("Bye bye...");

	return 0;
}
