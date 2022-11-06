#include "constParametrs.hpp"

constParametrs::constParametrs(float weight, float length, float width)
{
    this->weight = weight;

    this->length = length;

    this->width = width;
}

constParametrs::constParametrs(const constParametrs & other)
{
    this->weight = other.weight;

    this->length = other.length;

    this->width = other.width;
}
constParametrs::constParametrs()
{
    this->weight = 0;

    this->length = 0;

    this->width = 0;
}