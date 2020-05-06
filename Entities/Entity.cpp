#include "Entity.h"
#include <SFML/Window/Event.hpp>
#include "../Events/Event.h"
#include "../Events/EventMethodsInterfaces.h"

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
		auto name = fqn.substr(fqn.find_last_of(':') + 1);
#endif

		return name;
	}

	void Entity::onEvent(Event& ev)
	{
		// todo - optimize, dynamic_cast costs enormous amount of cycles
#pragma region Helper macros
#define CAST_VAR(name) castTo##name
#define CAST_AND_CALL(name)                                    \
	auto* CAST_VAR(name) = dynamic_cast<EVINAME(name)*>(this); \
	if (CAST_VAR(name) != NULL)                                \
	{                                                          \
		CAST_VAR(name)->on##name(ev);                          \
	}
#pragma endregion

		const auto& orgEv = ev.getOriginalEvent();

		switch (orgEv.type)
		{
			case sf::Event::MouseButtonReleased:
			{
				CAST_AND_CALL(MouseButtonClick);

				if (orgEv.mouseButton.button == sf::Mouse::Button::Left)
				{
					CAST_AND_CALL(MouseLeftButtonClick);
				}
				else if (orgEv.mouseButton.button == sf::Mouse::Button::Right)
				{
					CAST_AND_CALL(MouseRightButtonClick);
				}
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

#pragma region Helper macros
#undef CAST_AND_CALL
#undef CAST_VAR
#pragma endregion
	}

	const sf::FloatRect& Entity::getRect() const
	{
		return m_rect;
	}

	GUID Entity::getEntityId()
	{
		return entity_id;
	}

	uint16_t Entity::getZIndex() const
	{
		return m_zIndex;
	}

	void Entity::setZIndex(uint16_t zIndex)
	{
		m_zIndex = zIndex;
	}
}
