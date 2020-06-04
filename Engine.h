#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <functional>
#include "Entities/Tiles/TiledMap.h"
#include "Foundation/Object.h"
#include "GameState.h"
#include "Screen/Renderer.h"

// @formatter:off
// clang-format off
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <threadpoolapiset.h>
#include <chrono>
// @formatter:on
// clang-format on

#pragma comment(lib, "Kernel32.lib")

namespace Godamn
{
	/**
	 * @class Engine
	 *
	 * @brief Main class holding and combining everything within game, manages event loop
	 */
	class Engine : sf::NonCopyable, public Object, public Renderer
	{
	public:
		enum class EngineEvent {
			// Called after engine was fully initialized
			Initialized
		};

		// void ()
		typedef std::function<void(void)> RemoveElementCallback;
		// void (uint64_t deltaTime, std::function<void()> removeTimer)
		typedef std::function<void(uint64_t, RemoveElementCallback)> TimerCallback;
		// uint64_t lastCalled, uint32_t interval, TimerCallback callback
		typedef std::tuple<uint64_t, uint32_t, TimerCallback> TimerTuple;
		// uint64_t keyType, TimerTuple valueType
		typedef std::map<uint64_t, TimerTuple> TimerMap;
		// void (std::function<void()> removeListener)
		typedef std::function<void(RemoveElementCallback)> EngineEventCallback;
		// uint64_t id, EngineEventCallback callback
		typedef std::map<uint64_t, EngineEventCallback> EngineEventTupleMap;
		// EngineEvent keyType, EngineEventTupleMap valueType
		typedef std::map<EngineEvent, EngineEventTupleMap> EngineEventMap;


	private:
		sf::Font m_mainFont;
		sf::Font m_altFont;
		std::shared_ptr<sf::RenderWindow> m_renderer;
		PTP_POOL m_threadPool;
		PTP_TIMER m_timer;
		TimerMap m_timerCallbacks;
		EngineEventMap m_eventMap;

	public:
		Engine();
		~Engine();
		/**
		 * @brief Runs initial checks (i.e: if all assets are present)
		 */
		void runChecks();
		/**
		 * @brief Pre loads required assets and initializes renderer
		 */
		void initialize();
		/**
		 * @brief Spawns game engine and enters event loop
		 */
		int spawn();
		/**
		 * @brief Returns geometry of the window
		 */
		const sf::FloatRect getGeometry() const;
		/**
		 * @brief Returns underlying renderer window instance
		 */
		const sf::RenderWindow& getRenderWindow() const;
		/**
		 * @brief Appends timer event to engine
		 * @param interval Milliseconds
		 * @param callback
		 * @return Timer identifier used to remove it from callback map
		 * @example
		 *
		 * listenTimer(1000, [](uint64_t elapsedTimeSinceLastCall, auto deleteTimer) -> void {
		 *     // timer will eval every 1000 milliseconds = 1s
		 * })
		 */
		uint64_t listenTimer(uint32_t interval, TimerCallback callback);
		/**
		 * @brief Returns current time in unix timestamp
		 */
		static uint64_t getCurrentTimestamp();
		const sf::Font& getMainFont() const;
		/**
		 * @brief Listens for event on engine
		 * @param eventType type of event to listen
		 * @param callback
		 * @example
		 *
		 * listenEvent(EngineEvent::Initialized, [](auto removeListener) -> void {
		 *     // called right after engine init
		 *     // removeListener() <- will remove listener
		 * })
		 */
		uint64_t listenEvent(EngineEvent eventType, EngineEventCallback callback);

	private:
		/**
		 * @brief Returns common event occurrence position
		 *
		 * @remarks Built-in sf::Event has many event types and each has own mouse struct, so translator is required
		 */
		static sf::Vector2f translateEventPosition(const sf::Event& event);
		/**
		 * @brief Propagates event from event loop to concrete entities
		 */
		void propagateEvent(const sf::Event& event);
		/**
		 * @brief Used by thread pool timer as a callback function
		 */
		static void CALLBACK timerCallback(PTP_CALLBACK_INSTANCE hInst, PVOID ctx, PTP_TIMER timer);
		void callEngineEvents(EngineEvent eventType);
	};
}
