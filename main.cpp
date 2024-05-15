#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include<iostream>
#include <vector>

#include "include/SFML/Graphics.hpp"
#include "src/screen.hpp"

static void simulate(sf::Time delta) 
{
     
}

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::Clock clock;
    sf::Time time_curr;
    sf::Time time_prev;
   

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
        ScreenUpdate();
        simulate(delta);
        window.display();
    }

    return 0;
}