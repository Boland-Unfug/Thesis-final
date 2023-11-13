#pragma once
#include "../Strategies.hpp"

class RandomMove : public MovementStrategy
{
public:
    int do_move(int x_acceleration, int y_acceleration)
    {
        return 0, 0;
    }

    std::string toString() const
    {
        return "RandomMove";
    }
};