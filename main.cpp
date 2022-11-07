#include "Object.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");
    
    Object cube(constParametrs(10, 50, 50));
    cube.shape.setPosition(sf::Vector2f(350, 100));

    Object floor(constParametrs(1000000, 700, 30));
    floor.shape.setPosition(sf::Vector2f(0, 600));

    current cubres = cube.get_resultant();
    cubres.vector_coordinates.x /= 300;
    cubres.vector_coordinates.y /= 300;

    while (window.isOpen())
    {
        sf::Event event;
        window.clear();

        cube.move(cubres.vector_coordinates);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(cube.shape);

        window.draw(floor.shape);

        window.display();
    }

    return 0;
}
