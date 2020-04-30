#pragma once

#include "../Engine.h"
#include "Object.h"

namespace Godamn
{
	class Store;

	/**
	 * @brief Simple & small container
	 */
	class Container : public Object
	{
		std::shared_ptr<Engine> m_engine;
		std::shared_ptr<Store> m_store;

	public:
		/**
		 * We're denying moving or copying container
		 */
		Container(const Container&) = delete;
		Container(Container&& other) = delete;
		Container& operator=(const Container&) = delete;
		Container& operator=(Container&&) = delete;

		std::shared_ptr<Store> getStore() const;
		void setStore(Store* store);
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
