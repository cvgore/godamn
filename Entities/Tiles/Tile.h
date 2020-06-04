#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "../Entity.h"
#include "../../Events/EventMethodsInterfaces.h"
#include "TileEnum.h"

namespace Godamn
{
	class Event;

	class Tile : public Entity, public IEvMouseButtonClick, public IEvMouseOver
	{
		TileEnum m_type;
		bool m_vertexOutdated;
		bool m_unveiled;
		sf::Vector2<uint8_t> m_posOnMap;

	public:
		inline static constexpr EntityID entity_id = 0x0020;

		Tile(const sf::FloatRect& rect, sf::Vector2<uint8_t> posOnMap = {0, 0}, TileEnum type = TileEnum::Grass);
		TileEnum getType() const;
		void setType(TileEnum type);
		bool isOutdated();
		bool isUnveiled() const;
		void unveil();
		void onMouseButtonClick(Event& ev) override;
		void onMouseOver(Event &ev) override;
		std::string getTypeString() const;
		sf::Vector2<uint8_t> getPosOnMap() const;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
