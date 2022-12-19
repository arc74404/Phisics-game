#include "game.hpp"

#include <iostream>

void
game::run()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");

    Object defaultCube(constParametrs(50, 50, 50), 0);
    defaultCube.shape.setPosition(400, 30);
    world.emplace_back(defaultCube);

    Object LeftWall(constParametrs(200, 700, 25), 1);
    LeftWall.shape.setPosition(30, 0);

    Object floorWall(constParametrs(200, 700, 25), 2);
    floorWall.shape.setPosition(0, 600);

    sf::RectangleShape mamka;
    mamka.setFillColor(sf::Color::White);
    mamka.setPosition(sf::Vector2f(100, 100));
    mamka.setSize(sf::Vector2f(100, 100));
    mamka.setOutlineThickness(20);
    mamka.setOutlineColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Green);

        defaultCube.move(floorWall);

        window.draw(defaultCube.shape);
        window.draw(floorWall.shape);
        window.display();
    }

    return;
}