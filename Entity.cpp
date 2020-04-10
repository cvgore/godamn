#include "Entity.h"

#include <SFML/Window/Event.hpp>
#include "EventMethodsInterfaces.h"
#include "Event.h"
#include <SFML/Graphics/RenderTarget.hpp>

namespace Godamn
{
	Entity::Entity(const sf::FloatRect& rect)
	{
		this->m_rect = rect;
		this->setPosition(rect.left, rect.top);
	}

	const char* Entity::getName() const
	{
		const auto name = typeid(*this).name();

		return strncmp(name, "Entity", 16) == 0 ? "?unknown" : name;
	}

	void Entity::onEvent(Event& ev)
	{
#pragma region <Helper macros
#define CAST_VAR(name) castTo##name
#define CAST_AND_CALL(name) auto* CAST_VAR(name) = dynamic_cast<EVINAME(name)*>(this); \
	if (CAST_VAR(name) != NULL) { \
		CAST_VAR(name)->on##name(ev); \
	}
#pragma endregion

		auto& orgEv = ev.getOriginalEvent();
		
		switch (orgEv.type)
		{
		case sf::Event::MouseButtonReleased:
		{
			CAST_AND_CALL(MouseClick);
		}
		break;
		case sf::Event::MouseMoved:
		{
			CAST_AND_CALL(MouseOver);
		}
		break;
		default:
			break;
		}

		/*CAST_AND_CALL(MouseClick)
		CAST_AND_CALL(MouseOver)
		CAST_AND_CALL(KeyPress)*/

#pragma region </Helper macros
#undef CAST_AND_CALL
#undef CAST_VAR
#pragma endregion
	}

	const sf::FloatRect& Entity::getRect() const
	{
		return this->m_rect;
	}
}
