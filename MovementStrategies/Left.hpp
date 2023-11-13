#pragma once
#include "../Strategies.hpp"

class Left : public MovementStrategy
{
public:
    int do_move(int x_acceleration, int y_acceleration)
    {
        return -1, 0;
    }

    std::string toString() const
    {
        return "RandomMove";
    }
};