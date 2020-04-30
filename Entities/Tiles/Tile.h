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

	class Tile : public Entity, public IEvMouseButtonClick
	{
		TileEnum m_type;
		bool m_vertexOutdated;

	public:
		// {7D07691B-7193-4403-B668-CB9B2A1CA1EF}
		inline static constexpr GUID entity_id = {
			0x7d07691b, 0x7193, 0x4403, {0xb6, 0x68, 0xcb, 0x9b, 0x2a, 0x1c, 0xa1, 0xef}
		};

		Tile(const sf::FloatRect& rect, TileEnum type = TileEnum::Grass);
		TileEnum getType() const;
		void setType(TileEnum type);
		bool isOutdated();
		void onMouseButtonClick(Event& ev) override;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
