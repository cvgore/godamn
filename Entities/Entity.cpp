#include "Entity.h"
#include "../Events/EventMethodsInterfaces.h"
#include "../Events/Event.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace Godamn
{
	Entity::Entity(const sf::FloatRect& rect)
	{
		m_rect = rect;

		setPosition(rect.left, rect.top);
	}

	std::string Entity::getName() const
	{
		// MSVC returns human-readable FQN, other returns mangled FQN
#if _MSC_VER
		const auto fqn = std::string(typeid(*this).name());
		const auto name = fqn.substr(fqn.find_last_of(':') + 1);
#endif

		return name;
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
		return m_rect;
	}
}
