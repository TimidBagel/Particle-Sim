#include "../Component.hpp"
#include <iostream>
#include <ostream>

namespace ecs {
	class Health : public Component {
	public:
	float HP=5;
	 Health(int h){
		HP=h;
	}
	 Health(){
		
	}
	 void update() {
		if(HP>=0){
			std::cout<<HP<<std::endl;
			HP-=1;
		}
		}
	};
	
}
