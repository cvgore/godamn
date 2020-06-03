#pragma once

#include <memory>
#include <vector>
#include "../Entities/Entity.h"

namespace Godamn
{
	class Engine;

	class Scene : public Entity
	{
		friend class Engine;

	public:
		typedef std::shared_ptr<Entity> SPEntity;
		typedef std::vector<SPEntity> EntitiesArray;

	protected:
		EntitiesArray m_entities;
		bool m_zIndexOutdated;

	public:
		inline static constexpr uint16_t entity_id = 0x0022;

		Scene();

		SPEntity addEntity(Entity* entity);
		EntitiesArray::iterator begin();
		EntitiesArray::iterator end();
		EntitiesArray::iterator findEntityByEntityId(const std::string id);

	protected:
		Scene(const sf::FloatRect& rect);

		void beforeDraw(const Renderer& renderer) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
