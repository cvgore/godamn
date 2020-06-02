#pragma once

#include "../Events/EventMethodsInterfaces.h"
#include "../Scenery/Scene.h"
#include "Entity.h"
#include <include/SFML/Graphics/Text.hpp>

namespace Godamn
{
	class Hud : public Scene, public IEvMouseButtonClick
	{
		sf::Text* m_faithPointsText;
	public:
		Hud(const sf::FloatRect& rect);

		void onMouseButtonClick(Event& ev) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void beforeDraw(const Renderer &renderer) override;
	};
}
