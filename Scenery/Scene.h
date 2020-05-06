#pragma once

#include <memory>
#include <vector>
#include "../Screen/ScreenObject.h"
#include "../Engine.h"

namespace Godamn
{
	class Entity;

	class Scene : public ScreenObject
	{
		friend class Engine;

	public:
		typedef std::shared_ptr<Entity> SPEntity;
		typedef std::vector<SPEntity> EntitiesArray;

	private:
		EntitiesArray m_entities;
		bool m_zIndexOutdated;

	public:
		Scene();
		void addEntity(Entity* entity);
		EntitiesArray::iterator begin();
		EntitiesArray::iterator end();
		EntitiesArray::iterator findEntityByGuid(const GUID& guid);

	protected:
		void beforeDraw(const Renderer& renderer) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
