#include "Hud.h"
#include <include/SFML/Graphics/RectangleShape.hpp>
#include <include/SFML/Graphics/Text.hpp>
#include "AnonymousEntity.h"
#include "../Foundation/Container.h"
#include "../Engine.h"
#include <iomanip>
#include <sstream>

namespace Godamn
{
	Hud::Hud(const sf::FloatRect& rect): Scene(rect)
	{
		auto hudBgEnt = __new AnonymousEntity<sf::RectangleShape>(
			__new sf::RectangleShape({ rect.width, rect.height }),
			rect
		);
		auto hudBgShp = (*hudBgEnt);

 		addEntity(hudBgEnt);

		hudBgShp->setFillColor({60, 55, 95});


		auto faithPointsEnt = __new AnonymousEntity<sf::Text>(
			__new sf::Text(L"<faithPts>", getContainer().getEngine()->getMainFont(), 16),
			{ rect.left + 8.f, rect.top + 8.f, 128.f, 20.f }
 		);
		auto faithPointsTxt = (*faithPointsEnt);
		m_faithPointsText = faithPointsTxt.get().get();

		addEntity(faithPointsEnt);

		faithPointsTxt->setFillColor(sf::Color::White);


		auto woodAmountEnt = __new AnonymousEntity<sf::Text>(
		__new sf::Text(L"<woodAmount>", getContainer().getEngine()->getMainFont(), 16),
		{ rect.left + 8.f, rect.top + 8.f, 128.f, 20.f }
		);
		auto woodAmountTxt = (*woodAmountEnt);
		m_faithPointsText = woodAmountTxt.get().get();

		addEntity(woodAmountEnt);

		woodAmountTxt->setFillColor(sf::Color::White);
	}

	void Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		Scene::draw(target, states);
	}

	void Hud::onMouseButtonClick(Event& ev)
	{
		// noop
	}

	void Hud::beforeDraw(const Renderer& renderer)
	{
		std::stringstream str;
		str << "FP: " << std::setw(12) << getContainer().getGameState()->getResources().faith;

		m_faithPointsText->setString(str.str());

		Scene::beforeDraw(renderer);
	}
}
