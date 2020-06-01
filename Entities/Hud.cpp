#include "Hud.h"
#include <include/SFML/Graphics/RectangleShape.hpp>
#include "AnonymousEntity.h"

namespace Godamn
{
	Hud::Hud(const sf::FloatRect& rect): Scene(rect)
	{
		auto hudBg = addEntity(__new AnonymousEntity<sf::RectangleShape>(__new sf::RectangleShape({ rect.width, rect.height }), rect));
		hudBg.get()->get
		setPosition(rect.top, rect.left);

		hudBg.setPosition(getPosition());
		hudBg.setFillColor({20, 15, 45});
	}

	void Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// noop
	}

	void Hud::onMouseButtonClick(Event& ev)
	{
		// noop
	}
}
