#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "current.hpp"
#include "constParametrs.hpp"
#include <SFML/Graphics.hpp>

class Object
{
private:

	void create_shape();

	constParametrs parametrs;

	current resultant;

	sf::Clock clockTime;

	double time;

	int number;

	current impuls;
	current gravity;
public:

	sf::Vector2f speedVect;
	float speed;

	bool WasTouch;	
	
	sf::Vector2f A;
	
	void move(const Object& other);

	Object(constParametrs a, int n);

	void get_resultant(const Object&);
	
	sf::RectangleShape shape;

	void setSpeed();
	void setSpeedWithHook(const Object&);

	void printData();
};

#endif // !OBJECT_HPP
