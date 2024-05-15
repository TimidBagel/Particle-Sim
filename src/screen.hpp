#include <SFML/Graphics/RectangleShape.hpp>

struct Vector2{
    public:
    int x;
    int y;
    Vector2(int X, int Y){
        x=X;
        y=Y;
    }
    
};
class Pixel{
    public:
    Vector2 position;
};
void ScreenUpdate(){
     std::vector<Pixel> pixels;
    for (auto &p : pixels) {
                sf::RectangleShape this_pixel = sf::RectangleShape(sf::Vector2f(1,1));
                this_pixel.setPosition(p.position.x, p.position.y);
            }
}