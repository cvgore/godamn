#pragma once

/**
 * @brief Creates common event interface name, f.e: MouseClick => IEvMouseClick
 */
#define EVINAME(name) IEv##name

#define MAKE_EVENT_INTERFACE(name) class EVINAME(name) \
	{\
	public:\
		virtual ~EVINAME(name)() {/* noop */};\
		virtual void on##name(Event& ev) = 0;\
	};


namespace Godamn
{
	class Event;
	
	MAKE_EVENT_INTERFACE(MouseClick)

	MAKE_EVENT_INTERFACE(MouseOver)

	MAKE_EVENT_INTERFACE(KeyPress)
}

#undef MAKE_EVENT_INTERFACE
