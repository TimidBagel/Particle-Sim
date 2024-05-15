#pragma once

#include "Component.hpp"
#include "Entity.hpp"

static class EntityManager {
	std::vector<std::shared_ptr<Entity>> entities;

	void add_entity(std::shared_ptr<Entity> entity) {
		entities.push_back(entity);
	}
};