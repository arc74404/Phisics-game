#include "current.hpp"

#include <iostream>

#include "cmath"

#define PI 3.14159265358979323846

current&
current::operator=(const current& other)
{

    this->direction = other.direction;

    this->Vector_coordinates = other.Vector_coordinates;

    this->power = other.power;

    return *this;
}
current::current()
{
    direction = 0;

    power = 0;
};
current::current(float dd)
{
    direction = dd;

    power = 0;
}
void
current::setPower(float p)
{
    this->power = p;
}
float
current::getPower() const
{
    return this->power;
}

void
current::setDirection(float dd)
{
    direction = dd;
}
float
current::getDirection() const
{
    return direction;
}
void
current::setVector_coordinates()
{

    Vector_coordinates.x = (cos(direction * PI / 180));
    Vector_coordinates.y = (sin(direction * PI / 180));

    if (direction == 180 || direction == 0) Vector_coordinates.y = 0;
    if (direction == 90 || direction == 270) Vector_coordinates.x = 0;
}

void
current::setVector_coordinates(sf::Vector2f v)
{
    Vector_coordinates = v;
}

int
artan(sf::Vector2f a)
{
    int corn = 0;
    if (a.x > 0 && a.y > 0)
    {
        corn = atan(abs(a.x / a.y)) * 180 / PI;
    }
    else if (a.x < 0 && a.y > 0)
    {
        corn = 90 + atan(abs(a.x / a.y)) * 180 / PI;
    }
    else if (a.x > 0 && a.y < 0)
    {
        corn = 360 - atan(abs(a.x / a.y)) * 180 / PI;
    }
    else if (a.x < 0 && a.y < 0)
    {
        corn = 270 - atan(abs(a.x / a.y)) * 180 / PI;
    }
    else
    {
        if (a.x == 0)
        {
            if (a.y > 0)
            {
                corn = 90;
            }
            if (a.y < 0)
            {
                corn = 270;
            }
        }
        if (a.y == 0)
        {
            if (a.x > 0)
            {
                corn = 0;
            }
            if (a.x < 0)
            {
                corn = 180;
            }
        }
    }
    return corn;
}
void
current::Null()
{
    Vector_coordinates.x = 0;
    Vector_coordinates.y = 0;
    power                = 0;
    direction            = 0;
}
current
current::operator+(const current& other)
{
    current sum;

    sf::Vector2f help(this->Vector_coordinates * this->getPower() +
                      other.Vector_coordinates * other.getPower());

    sum.setDirection(artan(help));
    sum.setVector_coordinates();

    float pp = sqrt(pow(help.x, 2) + pow(help.y, 2)) /
               sqrt(pow(sum.Vector_coordinates.x, 2) +
                    pow(sum.Vector_coordinates.y, 2));
    sum.setPower(pp);

    return sum;
}