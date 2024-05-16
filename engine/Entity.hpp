// kits testing to try and figure out entitycomponent
#include "Component.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <typeinfo>
#include <vector>
namespace ecs {
class Entity {
public:
  std::vector<std::shared_ptr<Component>> components;
  template <typename T>

  T get_component() {
    T instance = T();
    for (auto &comp : components) {

      T *end = static_cast<T *>(&instance);

      if (typeid(*end).name() == typeid(instance).name()) {

        return *end;
      }
    }

    return instance;
  }

  template <typename T> void add_component() {
    std::shared_ptr<T> instance = std::shared_ptr<T>(new T());
    components.emplace_back(instance);
  }
};
} // namespace ecs
