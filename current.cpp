#include"current.hpp"
#include"math.h"

#define PI 3.14159265358979323846

current& current::operator=(const current& other){
    this->power_module = other.power_module;

    return *this;
}

current::current( float dd){
    direction = dd;
}

void current::setPowerModule(float pm){
    this->power_module = pm;
}
float current::getPowerModule(){
    return this->power_module;
}
void current::setVector_coordinates()
{
    vector_coordinates.x = sin(direction * PI/180) * power_module;
    vector_coordinates.y = -(cos(direction * PI/180) * power_module);
}
