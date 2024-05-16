#pragma once

#include<iostream>
#include<vector>
#include<memory>

#include<stdexcept>
#include "Component.hpp"

class Entity {
private:
	std::vector<std::shared_ptr<ecs::Component>> components;
public:
	void add_component(std::shared_ptr<ecs::Component> component) {
		/// TODO: prevent duplicate components
		components.push_back(component);
	}

	template<typename T>
	T get_component() {
		if constexpr (!std::is_base_of_v<ecs::Component, T>()) {
			throw std::invalid_argument("Dude, wrong type man. Try again.");
		}
		for (auto& component : components) {
			// cast the component as `T` to check if it's the same type
			if (auto ptr = std::dynamic_pointer_cast<T>(component)) {
				// if cast successful, return pointer of type
				return ptr;
			}
		}
		std::cerr << "Component not found in entity" << std::endl;
	}	

	void update() {
		for (auto& component : components) {
			component->update();
		}
	}
};