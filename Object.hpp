#include "current.hpp"
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

public:

	sf::Vector2f vector_coordinates;//направление в точках перемещения
	
	void move(sf::Vector2f);

	Object(constParametrs a);

	current get_resultant();

	sf::RectangleShape shape;

	void Object::setVector_coordinates();
};

#endif // !OBJECT_HPP
