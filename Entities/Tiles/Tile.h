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

	public:
		inline static constexpr EntityID entity_id = 0x0020;

		Tile(const sf::FloatRect& rect, TileEnum type = TileEnum::Grass);
		TileEnum getType() const;
		void setType(TileEnum type);
		bool isOutdated();
		bool isUnveiled() const;
		void unveil();
		void onMouseButtonClick(Event& ev) override;
		void onMouseOver(Event &ev) override;
		std::string getTypeString() const;
	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
