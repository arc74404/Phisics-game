#ifndef CURRENTS_HPP
#define CURRENTS_HPP 

#include <SFML/Graphics/Vertex.hpp>

class current {

    float direction;//направление в углах

    float power_module;//модуль силы

public:

    sf::Vector2f vector_coordinates;//направление в точках перемещения

    current(float dd);

    current & operator=(const current& other);

    void setPowerModule(float);

    void setVector_coordinates();
};

#endif // !CURRENTS_HPP 