#pragma once
#include <iostream>
#include <ostream>
namespace ecs {
	class Component {
	public:
		virtual void update() { std::cout << "parentcall" << std::endl; };
		virtual ~Component() {}
	};
}


