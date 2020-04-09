// ReSharper disable CppClangTidyCppcoreguidelinesSpecialMemberFunctions
#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "HandlesEvents.h"
#include "IRelativePos.h"

namespace Godamn
{
	// This class handles all entities within game (except Player & Hud)
	class Entity : public sf::Drawable, public sf::Transformable, public HandlesEvents, IRelativePos
	{
	public:
		Entity() = default;
		virtual ~Entity() = default;
		virtual const char* getName() const;
		void onEvent(Event& ev) override;
		// void 
	};
}
