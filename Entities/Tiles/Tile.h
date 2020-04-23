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

	class Tile : public Entity, public IEvMouseClick
	{
	public:
		Tile(const sf::FloatRect& rect, TileEnum type = TileEnum::VOID);
		TileEnum getType() const;
		void setType(TileEnum type);
		bool isOutdated();
		void onMouseClick(Event& ev) override;

	private:
		TileEnum m_type;
		bool m_vertexOutdated;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
