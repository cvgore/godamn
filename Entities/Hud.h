#pragma once

#include "../Events/EventMethodsInterfaces.h"
#include "../Scenery/Scene.h"
#include "Entity.h"
#include <include/SFML/Graphics/Text.hpp>

namespace Godamn
{
	class Hud : public Scene, public IEvMouseButtonClick, public IEvKeyPress
	{
		sf::Text* m_faithPointsText;
		sf::Text* m_woodAmountText;
		sf::Text* m_stoneAmountText;
		sf::Text* m_peopleAmountText;
		sf::Text* m_currentModeText;
		sf::Text* m_modesText;
		sf::Text* m_currentlySelectedTile;
		sf::Text* m_currentlyHoveredTile;

	public:
		inline static constexpr EntityID entity_id = 0x0023;
		Hud(const sf::FloatRect& rect);

		void onMouseButtonClick(Event& ev) override;
		void onKeyPress(Event &ev) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void beforeDraw(const Renderer &renderer) override;
	};
}
