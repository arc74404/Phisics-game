#include "Object.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");
    
    Object cube(constParametrs(10, 50, 50));
    cube.setPosition(sf::Vector2f(350, 100));

    Object floor(constParametrs(1000000, 700, 30));
    floor.setPosition(sf::Vector2f(0, 600));


    while (window.isOpen())
    {
        sf::Event event;

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