#pragma once

#include "Component.hpp"
#include "Entity.hpp"
namespace ecs {
class EntityManager {
public:
  std::vector<ecs::Entity> all_entities;
  void update() {
    for (auto &entity : all_entities) {
      for (auto &comp : entity.components) {

        comp->update();
      }
    }
  }
};
}; // namespace ecs
