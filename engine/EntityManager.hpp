#pragma once

#include "Component.hpp"
#include "Entity.hpp"
namespace ecs {
	class EntityManager {
	public:
		std::vector<ecs::Entity> entities;
		void update() {
			for (auto& entity : entities) {
				for (auto& comp : entity.components) {
					comp->update();
				}
			}
		}

		void add_entity(ecs::Entity entity) {
			entities.push_back(entity);
		}
	};
}; // namespace ecs
