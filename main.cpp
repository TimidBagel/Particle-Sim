#include<iostream>
#include <ostream>
#include <vector>

#include "engine/Component.hpp"
#include "include/SFML/Graphics.hpp"
#include "engine/Entity.hpp"
#include "engine/builtincomponents/Health.hpp"

 static std::vector<ecs::Entity> AllEntities;
using  namespace ecs;
static void simulate(sf::Time delta) 
{
   
    for (auto& entity : AllEntities) {
        for (auto& comp : entity.components) {
            
            comp->update();
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::Clock clock;
    sf::Time time_curr;
    sf::Time time_prev;
   
    ecs::Entity newEntity = ecs::Entity();
    ecs::Health healthComp = ecs::Health();
   
    newEntity.add_component<ecs::Health>();
    AllEntities.emplace_back(newEntity);
   

    while (window.isOpen())
    {
        time_curr = clock.restart();
        sf::Time delta = time_curr - time_prev;
        time_prev = time_curr;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        simulate(delta);
        window.display();
    }

    return 0;
}