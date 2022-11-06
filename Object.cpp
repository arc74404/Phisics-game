#include "Object.hpp"

void Object::create_shape()
{
    sf::RectangleShape shape2(sf::Vector2f(parametrs.length, parametrs.width));

    shape2.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));

    shape = shape2;
}

void Object::setPosition(sf::Vector2f pp)
{
    shape.setPosition(pp);
}

Object::Object(constParametrs a)
{
    parametrs = a;

    speed = 0;

    create_shape();
}

current Object::get_resultant(){

    current gravity(180);//сила тяжести
    float power_module = parametrs.weight * 9.80665;

	gravity.setPowerModule(power_module);
    gravity.setVector_coordinates();

    return gravity;
}