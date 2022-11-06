#include "current.hpp"
#include "constParametrs.hpp"

#include <SFML/Graphics.hpp>

#ifndef OBJECT_HPP
#define OBJECT_HPP

class Object
{
private:

	void create_shape();

	constParametrs parametrs;

	float speed;

	sf::Vector2f acceleration;//хранит в себе информацию, на сколько пикселей передвигать объект

public:

	sf::Vector2f vector_coordinates;//направление в точках перемещения
	
	void setPosition(sf::Vector2f);

	Object(constParametrs a);

	current get_resultant();

	sf::RectangleShape shape;

	void Object::setVector_coordinates();
};

#endif // !OBJECT_HPP