#ifndef CURRENTS_HPP
#define CURRENTS_HPP
#include <SFML/Graphics/Vertex.hpp>

class current
{

    int direction; // направление в углах

    float power; // сила

public:
    sf::Vector2f Vector_coordinates; // направление в точках перемещения

    current(float dd);
    current();

    current& operator=(const current& other);

    current operator+(const current& other);

    void setPower(float);
    float getPower() const;

    void setDirection(float dd);
    float getDirection() const;

    void setVector_coordinates();
    void setVector_coordinates(sf::Vector2f);

    void Null();
};

#endif // !CURRENTS_HPP
