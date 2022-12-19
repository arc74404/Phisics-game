#include "Object.hpp"

#include <iostream>
#include <thread>

#include "math.h"
#define ACCELERATION_OF_FREE_FALL 9.80665

void
Object::printData()
{
    std::cout << "number: #" << number << "\n"
              << "weight: " << parametrs.weight << "\n"
              << "speedVect.x: " << speedVect.x << '\n'
              << "speedVect.y: " << speedVect.y << '\n'
              << "time: " << time << '\n';
    std::cout << "####################" << '\n';
}
void
Object::create_shape()
{
    sf::RectangleShape shape2(sf::Vector2f(parametrs.length, parametrs.width));

    shape2.setFillColor(sf::Color::Black);

    shape = shape2;
}

void
Object::move(const Object& other)
{

    if (other.shape.getGlobalBounds().intersects(this->shape.getGlobalBounds()))
    {
        setSpeedWithHook(other);
        WasTouch = true;
    }
    else
    {
        get_resultant(other);
        WasTouch = false;
    }
    time = clockTime.restart().asSeconds() / 100;

    shape.move(speedVect.x, speedVect.y);
}

Object::Object(constParametrs a, int n)
{
    time      = 0;
    parametrs = a;
    speedVect = (sf::Vector2f(0, 0));
    impuls.Null();
    gravity.Null();
    speed  = 0;
    number = n;
    A      = sf::Vector2f(0, 0);
    create_shape();
}

void
Object::setSpeed()
{

    A.x = resultant.getPower() / parametrs.weight *
          resultant.Vector_coordinates.x * time;
    A.y = resultant.getPower() / parametrs.weight *
          resultant.Vector_coordinates.y * time;

    speedVect.x += A.x;
    speedVect.y += A.y;

    speed = sqrt(speedVect.x * speedVect.x + speedVect.y * speedVect.y);
}

void
Object::setSpeedWithHook(const Object& other)
{

    if (!WasTouch)
    {
        this->speedVect.x =
            -(2 * other.parametrs.weight * other.speedVect.x +
              this->speedVect.x *
                  (this->parametrs.weight - other.parametrs.weight)) /
            (this->parametrs.weight + other.parametrs.weight) / 2;
        this->speedVect.y =
            (2 * other.parametrs.weight * other.speedVect.y +
             this->speedVect.y *
                 (this->parametrs.weight - other.parametrs.weight)) /
            (this->parametrs.weight + other.parametrs.weight) / 2;
    }

    this->speed = sqrt(speedVect.x * speedVect.x + speedVect.y * speedVect.y);
}
void
Object::get_resultant(const Object& other)
{

    gravity.setDirection(90);
    gravity.setPower(parametrs.weight * ACCELERATION_OF_FREE_FALL);
    gravity.setVector_coordinates();

    resultant = gravity;

    setSpeed();
}
