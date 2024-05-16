#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdio>
#include<iostream>
#include <ostream>
#include <vector>

#include "include/SFML/Graphics.hpp"
#include "src/screen.hpp"
 static sf::View camera;
 const bool ENABLE_CAMERA_MOVEMENT = true;
static void simulate(sf::Time delta) 
{
    if(ENABLE_CAMERA_MOVEMENT){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        camera.move(-0.1,0);
    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        camera.move(0.1,0);
    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        camera.move(0,-0.1);
    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        camera.move(0,0.1);
    }
    }
    
           
}

int main() {
   
    sf::RenderWindow window(sf::VideoMode(screen::SCREEN_SIZE.x, screen::SCREEN_SIZE.y), "SFML works!", sf::Style::Titlebar|sf::Style::Close);
     camera = window.getDefaultView();
     camera.zoom(0.3f);
    sf::Clock clock;
    sf::Time time_curr;
    sf::Time time_prev;
    
   
   
    //temporary, to test that I can render stuff
    std::vector<screen::RenderPixel> render_pixels;
    for (int i =0; i<5000; i++) { 
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
             
           
           
        }

        window.clear();
        window.setView(camera);
        
        screen::update(window, render_pixels);
        simulate(delta);
        window.display();
    }

    return 0;
}