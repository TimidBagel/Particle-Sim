//kits testing to try and figure out entitycomponent
#include "Component.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <typeinfo>
#include <vector>
namespace ecs {
    class Entity{
    public:
    
    std::vector<std::shared_ptr<Component>> components;
    template <typename T> 
    
    T get_component(){
        T instance = T();
        for (auto& comp : components) {
            
             T * end = static_cast<T*>(&instance);
            
            if(typeid(*end).name() == typeid(instance).name()){
               
                return *end;
            }
        }
        //std::cout << "Target does not have that component!"<<std::endl;
        return instance;
    }
    // T get_component() {
	// 	if constexpr (!std::is_base_of_v<Component, T>()) {
	// 		throw std::invalid_argument("Dude, wrong type man. Try again.");
	// 	}
	// 	for (auto& component : components) {
	// 		// cast the component as `T` to check if it's the same type
	// 		if (auto ptr = std::dynamic_pointer_cast<T>(component)) {
	// 			// if cast successful, return pointer of type
	// 			return ptr;
	// 		}
	// 	}
	// 	std::cerr << "Component not found in entity" << std::endl;
	// }	
    template <typename T> 
     void add_component(){
        std::shared_ptr<T> instance = std::shared_ptr<T>(new T());
        components.emplace_back(instance);
     }
};
}
