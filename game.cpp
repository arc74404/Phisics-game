#include "game.hpp"
#include <iostream>

void game::run()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");

    Object defaultCube(constParametrs(50, 25, 25), 0);
    world.emplace_back(defaultCube);

    Object LeftWall(constParametrs(200, 700, 25), 1);
    LeftWall.shape.setPosition(30, 0);

    Object floorWall(constParametrs(200, 25, 700), 2);
    LeftWall.shape.setPosition(30, 0);

    sf::Event event;

    while (window.isOpen())
    {
        window.clear(sf::Color::Green);


        defaultCube.move(floorWall);

        window.clear();
        window.draw(defaultCube.shape);
        
        window.draw(floorWall.shape);

        window.draw(LeftWall.shape);

        window.display();
    }
    
    return;
}