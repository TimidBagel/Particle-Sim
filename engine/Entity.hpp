//kits testing to try and figure out entitycomponent
#include "Component.hpp"
#include <iostream>
#include <ostream>
#include <typeinfo>
#include <vector>
namespace ecs {
    class Entity{
    public:
    
    std::vector<Component*> components;
    template <typename T> 
    
    T get_component(){
        T instance = T();
        for (auto& comp : components) {
            //std::cout << typeid(comp).name()<<std::endl;
            // std::cout << typeid(instance).name()<<std::endl;
             T * end = static_cast<T*>(&instance);
             //std::cout << typeid(*end).name()<<std::endl;
            if(typeid(*end).name() == typeid(instance).name()){
               
                return *end;
            }
        }
        std::cout << "Target does not have that component!"<<std::endl;
        return instance;
    }
};
}
