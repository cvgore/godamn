#include "Entity.h"
#include <SFML/Window/Event.hpp>
#include <include/SFML/Graphics/RectangleShape.hpp>
#include "../../Screen/Renderer.h"
#include "../Events/Event.h"
#include "../Events/EventMethodsInterfaces.h"
#include "../Utils/Utils.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

int Godamn::Entity::m_debug = 0;

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
	if (CAST_VAR(name) != nullptr)                             \
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
			case sf::Event::KeyPressed:
			{
				keyboardDebug(ev);
				CAST_AND_CALL(KeyPress);
			}
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

	void Entity::afterDraw(const Renderer& renderer)
	{
		renderer.afterDraw(*this);
	}

	void Entity::beforeDraw(const Renderer& renderer)
	{
//		renderer.beforeDraw(*this);
	}

	uint16_t Entity::getZIndex() const
	{
		return m_zIndex;
	}

	void Entity::setZIndex(uint16_t zIndex)
	{
		zIndex = m_zIndex;
	}

	GUID Entity::getEntityId()
	{
		return entity_id;
	}

	void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
//		if ((m_debug & 1) == 1) {
//			sf::RectangleShape dbgRectOutline({ getRect().width, getRect().height });
//			dbgRectOutline.setPosition({ getRect().top, getRect().left });
//			dbgRectOutline.setOutlineThickness(1.f);
//			dbgRectOutline.setFillColor(sf::Color::Black);
//			dbgRectOutline.setOutlineColor(sf::Color::Red);
//
//			target.draw(dbgRectOutline);
//		}
	}

	void Entity::keyboardDebug(Event& ev)
	{
//		if (ev.getOriginalEvent().key.code == sf::Keyboard::F9) {
//			m_debug ^= 1;
//			DEBUG("Toggled entity outline, current m_debug value: %x", m_debug);
//		}
	}
}
