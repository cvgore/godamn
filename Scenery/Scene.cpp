#include "Scene.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "../Entities/Entity.h"

namespace Godamn
{
	Scene::Scene()
	{}

	void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& _entity : m_entities)
		{
			auto& entity = *_entity;

			entity.beforeDraw();
			target.draw(entity);
		}
	}

	void Scene::addEntity(Entity* entity)
	{
		m_entities.emplace_back(entity);
	}

	Scene::EntitiesArray::iterator Scene::begin()
	{
		return m_entities.begin();
	}

	Scene::EntitiesArray::iterator Scene::end()
	{
		return m_entities.end();
	}
}
