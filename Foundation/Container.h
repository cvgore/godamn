#pragma once

#include "../Engine.h"
#include "Object.h"

namespace Godamn
{
	/**
	 * @brief Simple & small container
	 */
	class Container : public Object
	{
		Engine* m_engine;

	public:
		Container(const Container&) = delete;
		Container(Container&& other) = delete;
		Container& operator=(const Container&) = delete;
		Container& operator=(Container&&) = delete;

		static Container& getInstance();

		Engine* getEngine() const;
		void setEngine(Engine* engine);

	private:
		/***
		 * We deny creation of container by anyone but container itself
		 */
		Container();
		~Container();
	};
}
