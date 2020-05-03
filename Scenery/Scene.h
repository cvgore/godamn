#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <memory>
#include <vector>

namespace Godamn
{
	class Entity;

	class Scene : public sf::Drawable, public sf::Transformable
	{
		typedef std::vector<std::shared_ptr<Entity>> EntitiesArray;
		EntitiesArray m_entities;

	public:
		Scene();
		void addEntity(Entity* entity);
		EntitiesArray::iterator begin();
		EntitiesArray::iterator end();

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
