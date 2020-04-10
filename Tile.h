#pragma once
#include "Entity.h"
#include "EventMethodsInterfaces.h"
#include "TileEnum.h"

namespace Godamn
{
	class Event;
	
	class Tile : public Entity, public IEvMouseClick
	{
	public:
		Tile(const sf::FloatRect& rect);
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
