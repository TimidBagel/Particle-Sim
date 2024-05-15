#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include<iostream>
#include <vector>

#include "include/SFML/Graphics.hpp"
#include "src/screen.hpp"

static void simulate(sf::Time delta) 
{
     
}

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Fullscreen);
    sf::Clock clock;
    sf::Time time_curr;
    sf::Time time_prev;
    //temporary, to test that I can render stuff
    std::vector<RenderPixel> render_pixels;
    for (int i =0; i<50; i++) { 
         RenderPixel testPixel = RenderPixel(sf::Vector2i(60+i,60+i), sf::Color::Red);
    render_pixels.emplace_back(testPixel);
    
    }
   

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
        screen_update(window, render_pixels);
        simulate(delta);
        window.display();
    }

    return 0;
}