#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdio>
#include<iostream>
#include <vector>

#include "include/SFML/Graphics.hpp"
#include "src/screen.hpp"

static void simulate(sf::Time delta) 
{
     
}

int main() {
    sf::RenderWindow window(sf::VideoMode(screen::ScreenSize.x, screen::ScreenSize.y), "SFML works!", sf::Style::Titlebar|sf::Style::Close);
    sf::Clock clock;
    sf::Time time_curr;
    sf::Time time_prev;
    sf::View camera(sf::FloatRect(200.f, 200.f, 300.f, 200.f));
    //temporary, to test that I can render stuff
    std::vector<screen::RenderPixel> render_pixels;
    for (int i =0; i<50; i++) { 
        screen::RenderPixel testPixel = screen::RenderPixel(sf::Vector2i(60+i,60+i), sf::Color::Red);
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
            if (event.type == sf::Event::Closed){
                window.close();
            }
                //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                    camera.move(sf::Vector2f(20,0));
                  //  printf("mover");
                //}
           
           
        }

        window.clear();
        screen::update(window, render_pixels);
        simulate(delta);
        window.display();
    }

    return 0;
}