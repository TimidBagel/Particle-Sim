#include <iostream>
#include <ostream>
#include <vector>

#include "engine/Component.hpp"
#include "engine/EntityManager.hpp"
#include "include/SFML/Graphics.hpp"

#include "engine/builtincomponents/Health.hpp"

using namespace ecs;
static ecs::EntityManager entity_manager;
static void simulate(sf::Time delta) { entity_manager.update(); }

int main() {
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::Clock clock;
  sf::Time time_curr;
  sf::Time time_prev;
  // For testing
  ecs::Entity newEntity = ecs::Entity();
  newEntity.add_component<ecs::Health>();
  entity_manager.all_entities.emplace_back(newEntity);

  while (window.isOpen()) {
    time_curr = clock.restart();
    sf::Time delta = time_curr - time_prev;
    time_prev = time_curr;

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    simulate(delta);
    window.display();
  }

  return 0;
}