#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace Godamn
{
	class Scene: public sf::Drawable, public sf::Transformable
	{
	public:
		Scene();

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
