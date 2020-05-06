#include "Scene.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "../Entities/Entity.h"

namespace Godamn
{
	Scene::Scene()
	{}

	void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& entityPtr : m_entities)
		{
			target.draw(*entityPtr);
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

	void Scene::beforeDraw(const Renderer& renderer)
	{
		if (m_zIndexOutdated)
		{
			std::sort(m_entities.begin(), m_entities.end(), [](Scene::SPEntity left, Scene::SPEntity right) {
				return left->getZIndex() < right->getZIndex();
			});

			m_zIndexOutdated = false;
		}

		for (auto& entityPtr : m_entities)
		{
			renderer.beforeDraw(*entityPtr);
		}
	}

	Scene::EntitiesArray::iterator Scene::findEntityByGuid(const GUID& guid)
	{
		return std::find_if(begin(), end(), [&guid](const std::shared_ptr<Entity>& ptr) {
			return ptr->getEntityId() == guid;
		});
	}
}
