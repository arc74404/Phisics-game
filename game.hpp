#ifndef GAME_HPP
#define GAME_HPP
#include <vector>
#include "Object.hpp"

class game
{
protected:
    std::vector<Object> world;
public:
    void run();
};
#endif //GAME_HPP