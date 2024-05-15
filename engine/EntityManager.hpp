#pragma once

#include "Component.hpp"
#include "Entity.hpp"

static class EntityManager {
private:
	std::vector<std::shared_ptr<Entity>> entities;

public:
	void add_entity(std::shared_ptr<Entity> entity) {
		entities.push_back(entity);
	}

	int remove_entity(std::shared_ptr<Entity> doomed_entity) {
		int entity_index = 0;
		for (auto& iter_entity : entities) {
			if (iter_entity == doomed_entity) {
				entities.erase(entities.begin() + entity_index);
				return entity_index;
			}
			entity_index++;
		}
	}
};