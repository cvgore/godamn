#pragma once

#include <memory>
#include "../Structs/EntityConfig.h"
#include "Object.h"

namespace Godamn
{
	class Engine;
	class EntityConfigStore;
	class SceneryManager;

	/**
	 * @brief Simple & small container
	 */
	class Container : public Object
	{
		std::shared_ptr<Engine> m_engine;
		std::shared_ptr<EntityConfigStore> m_entityStore;
		std::shared_ptr<SceneryManager> m_sceneryManager;

	public:
		/**
		 * We're denying moving or copying container
		 */
		Container(const Container&) = delete;
		Container(Container&& other) = delete;
		Container& operator=(const Container&) = delete;
		Container& operator=(Container&&) = delete;

		/**
		 * @brief Returns current instance of container
		 */
		static Container& getInstance();
		/**
		 * @deprecated
		 * @brief Disposes current instance resources, making container unusable
		 */
		void dispose();

		std::shared_ptr<Engine> getEngine() const;
		void setEngine(Engine* engine);

		void setEntityConfigStore(EntityConfigStore* store);
		std::shared_ptr<EntityConfigStore> getEntityConfigStore() const;

		void setSceneryManager(SceneryManager* manager);
		std::shared_ptr<SceneryManager> getSceneryManager() const;

	private:
		/**
		 * We deny creation of container by anyone but container itself
		 */
		Container();
		/**
		 * We deny destruction of container by anyone but container itself
		 */
		~Container() = default;
	};
}
