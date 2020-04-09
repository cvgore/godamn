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
		Tile();
		TileEnum getType() const;
		
		void onMouseClick(Event& ev) override;
		const sf::Vector2u getRelativePos() override;
		
	private:
		TileEnum m_type;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
