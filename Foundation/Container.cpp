#include "Container.h"
namespace Godamn
{
	Container::Container(Engine* engine)
	{
		m_engine = engine;
	}
	Engine* Container::getEngine() const
	{
		return m_engine;
	}
}