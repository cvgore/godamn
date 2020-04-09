#include "HandlesEvents.h"
#include "EventMethodsInterfaces.h"
#include "Event.h"

#define CAST_VAR(name) castTo##name
#define CAST_AND_CALL(name) auto* CAST_VAR(name) = dynamic_cast<EVINAME(name)*>(this); \
	if (CAST_VAR(name) != NULL) { \
		CAST_VAR(name)->on##name(ev); \
	}

namespace Godamn
{
	void HandlesEvents::onEvent(Event& ev)
	{
		if (ev.getOriginalEvent().type == sf::Event::MouseButtonReleased)
		{
			CAST_AND_CALL(MouseClick);
		}

		// if (ev.getOriginalEvent().type == sf::Event)
		
		/*CAST_AND_CALL(MouseClick)
		CAST_AND_CALL(MouseOver)
		CAST_AND_CALL(KeyPress)*/
	}
}

// We don't want to have that macro anywhere else
#undef CAST_AND_CALL
#undef CAST_VAR
