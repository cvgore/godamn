#include "main.h"

int main()
{
	LOG_DEBUG("Creating renderer...");
	
	sf::RenderWindow window(
		sf::VideoMode(800, 600),
		APP_NAME " " APP_VERSION,
		sf::Style::Default ^ sf::Style::Resize
	);

	LOG_DEBUG("Creating game instance...");
	
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		
		
		window.display();
	}

	LOG_DEBUG("Bye bye...");

	return 0;
}
