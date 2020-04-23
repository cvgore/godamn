#pragma once

#include "../Engine.h"

namespace Godamn
{
	/**
	 * @brief Simple & small IoC container
	 */
	class Container : public Object
	{
		Engine* m_engine;

	public:
		Container(const Container&) = delete;
		void operator=(const Container&) = delete;

		static Container& getInstance();

		Engine* getEngine() const;
		void setEngine(Engine* engine);

	private:
		Container();
	};
}
