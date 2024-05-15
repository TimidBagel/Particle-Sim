#include<iostream>

#include "include/SFML/Graphics.hpp"

static void simulate(sf::Time delta) {
    std::cout << delta.asMicroseconds();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::Clock clock;
    sf::Time time_curr;
    sf::Time time_prev;

    while (window.isOpen())
    {
        time_curr = clock.getElapsedTime();
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

        clock.restart();
    }

    return 0;
}