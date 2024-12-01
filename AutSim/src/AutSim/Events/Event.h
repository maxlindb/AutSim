#pragma once

#include "AutSim/Core.h"

#include <string>
#include <functional>

namespace AutSim {

	// Events in AutSim are currently blocking, meaning when an event occurs it is executed immediately. In the future this should probably instead be an event queue, processed during a specific point of every update, to prevent unnecessary blocking

	enum class EventType {
		None = 0,

		WindowClose = 1000,
		WindowResize = 1010,
		WindowFocus = 1020,
		WindowLostFocus = 1030,
		WindowMoved = 1040,

		AppTick = 2000,
		AppUpdate = 2010,
		AppRender = 2020,

		KeyPressed = 3000,
		KeyReleased = 3010,

		MouseButtonPressed = 4000,
		MouseButtonReleased = 4010,
		MouseMoved = 4020,
		MouseScrolled = 4030
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4),
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class AUTSIM_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	//this is from the video, but doesn't work. The version right below this method does, though.
	/*inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}*/

	inline std::string format_as(const Event& e) {
		return e.ToString();
	}
}