#pragma once

#include "../Events/EventMethodsInterfaces.h"
#include "../Scenery/Scene.h"
#include "Entity.h"

namespace Godamn
{
	class Hud : public Scene, public IEvMouseButtonClick
	{
	public:
		Hud(const sf::FloatRect& rect);

		void onMouseButtonClick(Event &ev) override;
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	};
}
