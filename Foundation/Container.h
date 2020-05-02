#pragma once

#include "../Structs/EntityConfig.h"
#include "Object.h"
#include <memory>

namespace Godamn
{
	class Engine;
	class EntityConfigStore;

	/**
	 * @brief Simple & small container
	 */
	class Container : public Object
	{
		std::shared_ptr<Engine> m_engine;
		std::shared_ptr<EntityConfigStore> m_entityStore;

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
		 * @brief Disposes current instance resources, making container unusable
		 */
		void dispose();

		std::shared_ptr<Engine> getEngine() const;
		void setEngine(Engine* engine);

		void setEntityConfigStore(EntityConfigStore* store);

		std::shared_ptr<EntityConfigStore> getEntityConfigStore() const;

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
