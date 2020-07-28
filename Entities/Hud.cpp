#include "Hud.h"
#include <SFML/Window/Event.hpp>
#include <include/SFML/Graphics/RectangleShape.hpp>
#include <include/SFML/Graphics/Text.hpp>
#include <iomanip>
#include <sstream>
#include "../Config/EntityConfigStore.h"
#include "../Engine.h"
#include "../Events/Event.h"
#include "../Foundation/Container.h"
#include "../Structs/ResPeople.h"
#include "AnonymousEntity.h"
#include "../Scenery/SceneryManager.h"
#include "../Scenery/Scene.h"

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
namespace Godamn
{
	Hud::Hud(const sf::FloatRect& rect) : Scene(rect)
	{
		auto hudBgEnt =
			__new AnonymousEntity<sf::RectangleShape>(__new sf::RectangleShape({ rect.width, rect.height }), rect);
		auto hudBgShp = (*hudBgEnt);

		addEntity(hudBgEnt);

		hudBgShp->setFillColor({ 60, 55, 95 });

		auto faithPointsEnt = __new AnonymousEntity<sf::Text>(
			__new sf::Text(L"<faithPts>", getContainer().getEngine()->getMainFont(), 16),
			{ rect.left + 8.f, rect.top + 8.f, 150.f, 16.f });
		auto faithPointsTxt = (*faithPointsEnt);
		m_faithPointsText = faithPointsTxt.get().get();

		addEntity(faithPointsEnt);

		faithPointsTxt->setFillColor(sf::Color::White);

		auto woodAmountEnt = __new AnonymousEntity<sf::Text>(
			__new sf::Text(L"<woodAmount>", getContainer().getEngine()->getMainFont(), 16),
			{ rect.left + 8.f, faithPointsTxt.getRect().top + faithPointsTxt.getRect().height + 8.f, 150.f, 16.f });
		auto woodAmountTxt = (*woodAmountEnt);
		m_woodAmountText = woodAmountTxt.get().get();

		addEntity(woodAmountEnt);

		woodAmountTxt->setFillColor(sf::Color::White);

		auto stoneAmountEnt = __new AnonymousEntity<sf::Text>(
			__new sf::Text(L"<stoneAmount>", getContainer().getEngine()->getMainFont(), 16),
			{ rect.left + 8.f, woodAmountTxt.getRect().top + woodAmountTxt.getRect().height + 8.f, 150.f, 16.f });
		auto stoneAmountTxt = (*stoneAmountEnt);
		m_stoneAmountText = stoneAmountTxt.get().get();

		addEntity(stoneAmountEnt);

		stoneAmountTxt->setFillColor(sf::Color::White);

		auto currentModeEnt = __new AnonymousEntity<sf::Text>(
			__new sf::Text(L"<currentMode>", getContainer().getEngine()->getMainFont(), 16),
			{ faithPointsTxt.getRect().left + faithPointsTxt.getRect().width + 8.f, rect.top + 8.f, 128.f, 16.f });
		auto currentModeTxt = (*currentModeEnt);
		m_currentModeText = currentModeTxt.get().get();

		addEntity(currentModeEnt);

		currentModeTxt->setFillColor(sf::Color::White);

		auto modesEnt = __new AnonymousEntity<sf::Text>(
			__new sf::Text(L"<modes>", getContainer().getEngine()->getMainFont(), 16),
			{ currentModeTxt.getRect().left + currentModeTxt.getRect().width + 8.f, currentModeTxt.getRect().top + 8.f,
			  250.f, 16.f });
		auto modesTxt = (*modesEnt);
		m_modesText = modesTxt.get().get();

		addEntity(modesEnt);

		modesTxt->setFillColor(sf::Color::White);

		auto currSelTileEnt = __new AnonymousEntity<sf::Text>(
			__new sf::Text(L"<selectedTile>", getContainer().getEngine()->getMainFont(), 16),
			{ modesTxt.getRect().left + modesTxt.getRect().width + 8.f, currentModeTxt.getRect().top + 8.f, 128.f, 16.f });
		auto currSelTileTxt = (*currSelTileEnt);
		m_currentlySelectedTile = currSelTileTxt.get().get();

		addEntity(currSelTileEnt);

		currSelTileTxt->setFillColor(sf::Color::White);

		auto currHovTileEnt = __new AnonymousEntity<sf::Text>(
			__new sf::Text(L"<hoveredTile>", getContainer().getEngine()->getMainFont(), 16),
			{ currSelTileTxt.getRect().left, currSelTileTxt.getRect().top + currSelTileTxt.getRect().height + 8.f, 128.f,
			  16.f });
		auto currHovTileTxt = (*currHovTileEnt);
		m_currentlyHoveredTile = currHovTileTxt.get().get();

		addEntity(currHovTileEnt);

		currHovTileTxt->setFillColor(sf::Color::White);
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
		auto& resources = getContainer().getGameState()->getResources();
		auto mode = getContainer().getGameState()->getMode();
		auto hovTile = getContainer().getGameState()->getCurrentlyHoveredTile();
		auto selTile = getContainer().getGameState()->getCurrentlySelectedTile();

		static std::stringstream str;
		str.str("");
		str.clear();

		str << "Faith Points: " << std::setw(12) << resources.faith;

		m_faithPointsText->setString(str.str());

		str.str("");
		str.clear();

		str << "Wood: " << std::setw(12) << resources.wood;

		m_woodAmountText->setString(str.str());

		str.str("");
		str.clear();

		str << "Stone: " << std::setw(12) << resources.stone;

		m_stoneAmountText->setString(str.str());

		str.str("");
		str.clear();

		str << "Mode: " << std::setw(12) << mode;

		m_currentModeText->setString(str.str());

		str.str("");
		str.clear();

		str << "[Q] - place lumber [W] - place temple"
			<< "\n"
			<< "[E] - place mine [R] - place chapel";

		m_modesText->setString(str.str());

		str.str("");
		str.clear();

		if (selTile != nullptr)
		{
			str << "Sel: " << selTile->getTypeString();
		}
		else
		{
			str << "Sel: "
				<< "nothing";
		}

		m_currentlySelectedTile->setString(str.str());

		str.str("");
		str.clear();

		if (hovTile != nullptr)
		{
			str << "Hov: " << hovTile->getTypeString();
		}
		else
		{
			str << "Hov: "
				<< "nothing";
		}

		m_currentlyHoveredTile->setString(str.str());

		Scene::beforeDraw(renderer);
	}

	void Hud::onKeyPress(Event& ev)
	{
		auto key = ev.getOriginalEvent().key.code;
		auto gs = getContainer().getGameState();
		auto selTile = gs->getCurrentlySelectedTile();

		if (selTile == nullptr ||
			!selTile->isUnveiled() || (selTile->getType() != TileEnum::Grass &&
				selTile->getType() != TileEnum::Grass_Forest && selTile->getType() != TileEnum::Grass_Stone))
		{
			return;
		}

		auto& resources = gs->getResources();
		auto cfgStore = getContainer().getEntityConfigStore();
		ResPeople needed;
		std::string cfgStoreKey;
		TileEnum tileType;

		switch (key)
		{
		case sf::Keyboard::Q:
			cfgStoreKey = "LoggingCamp";

			if (selTile->getType() != TileEnum::Grass_Forest)
			{
				
				return;
			}
			tileType = TileEnum::Grass_Lumber;
			break;
		case sf::Keyboard::W:
			cfgStoreKey = "Temple";
			tileType = TileEnum::Grass_Temple;
			break;
		case sf::Keyboard::E:
			cfgStoreKey = "Mine";
			if (selTile->getType() != TileEnum::Grass_Stone)
			{
				// TODO message why you can't place lumbermill there
				return;
			}
			tileType = TileEnum::Grass_Miner;
			break;
		case sf::Keyboard::R:
			cfgStoreKey = "Chapel";
			tileType = TileEnum::Grass_Chample;
			break;
		default:
			return;
		}

		needed = (*cfgStore)[cfgStoreKey].requirements;

		if (
			needed.res.stone <= resources.stone && needed.res.wood <= resources.wood && needed.res.faith <= resources.faith)
		{
			resources.faith -= needed.res.faith;
			resources.wood -= needed.res.wood;
			resources.stone -= needed.res.stone;
			selTile->setType(tileType);

			if (tileType == TileEnum::Grass_Chample) {
				auto tileMap = static_cast<TiledMap*>((*(getContainer().getSceneryManager()->getActiveScene()->findEntityByEntityId("TiledMap"))).get());

				tileMap->unveilWithChapel(selTile->getPosOnMap());
			}
		}
		else {
			MessageBoxA(getContainer().getEngine()->getRenderWindow().getSystemHandle(), "You need more resources!", "FAIL!", MB_APPLMODAL | MB_OK | MB_ICONWARNING);
		}
	}
	/*void display_not_placeable_msg(Tile* tile, TileEnum type )
	{
		MessageBoxA(getContainer().getEngine()->getRenderWindow().getSystemHandle(), "You need more resources!", "FAIL!", MB_APPLMODAL | MB_OK | MB_ICONWARNING);
	}*/
}
