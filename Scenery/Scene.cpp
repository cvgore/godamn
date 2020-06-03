#include "Scene.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "../Engine.h"
#include "../Foundation/Container.h"
#include "../Utils/Utils.h"

namespace Godamn
{
	Scene::Scene(): Entity(getContainer().getEngine()->getGeometry())
	{}

	void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& entityPtr : m_entities)
		{
			target.draw(*entityPtr);
		}
	}

    Scene::SPEntity Scene::addEntity(Entity* entity)
	{
		return m_entities.emplace_back(entity);
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

	Scene::EntitiesArray::iterator Scene::findEntityByEntityId(std::string id)
	{
		DEBUG("Search for entity: %s, start", id.c_str());
		return std::find_if(
		begin(), end(), [id](std::shared_ptr<Entity>& ptr) {
		  	DEBUG("Search for entity: %s, given: %s", id.c_str(), ptr->getName().c_str());
			return ptr->getName() == id;
		});
	}

	Scene::Scene(const sf::FloatRect& rect): Entity(rect)
	{}
}
