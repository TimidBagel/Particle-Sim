#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>
#include <ostream>
#include <vector>

#include "engine/Component.hpp"
#include "engine/EntityManager.hpp"
#include "include/SFML/Graphics.hpp"

#include "engine/components/Health.hpp"
#include "src/screen.hpp"

static ecs::EntityManager entity_manager;
static sf::View camera;
static void simulate(sf::Time delta) { entity_manager.update(); }

int main() {

	sf::RenderWindow window(sf::VideoMode(screen::SCREEN_SIZE.x, screen::SCREEN_SIZE.y), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
	camera = window.getDefaultView();
	camera.zoom(0.3f);
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
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		std::vector<screen::RenderPixel> render_pixels;

		window.clear();
		window.setView(camera);
		screen::update(window, render_pixels);
		simulate(delta);
		window.display();
	}

	return 0;
}