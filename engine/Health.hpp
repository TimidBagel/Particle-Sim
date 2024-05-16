#include "Component.hpp"
#include <iostream>
#include <ostream>

namespace ecs {
	class Health : public Component {
	public:
	float HP=50;
	 Health(){
		HP=50;
	}
	 void update() {
		if(HP>=0){
			std::cout<<HP<<std::endl;
			HP-=1;
		}
		}
	};
	
}
