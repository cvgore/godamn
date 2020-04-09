#pragma once

namespace Godamn
{
	class Event;
	
	class HandlesEvents
	{
	public:
		virtual ~HandlesEvents() = default;
		virtual void onEvent(Event& ev);
	};
}
