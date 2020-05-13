#pragma once

#include <memory>
#include <vector>
#include "../Engine.h"

namespace Godamn
{
	class Entity;

	class Scene : public Entity
	{
		friend class Engine;

	public:
		typedef std::shared_ptr<Entity> SPEntity;
		typedef std::vector<SPEntity> EntitiesArray;

	private:
		EntitiesArray m_entities;
		bool m_zIndexOutdated;

	public:
		// {38D97F0A-4D56-4AF3-9F4F-EC78D5C90A58}
		inline static constexpr GUID entity_id = {
		0x38d97f0a, 0x4d56, 0x4af3, { 0x9f, 0x4f, 0xec, 0x78, 0xd5, 0xc9, 0x0a, 0x58 }
		};

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
