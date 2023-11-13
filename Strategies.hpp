#include "History.hpp"
#include "Game.hpp"

#pragma once

class GameStrategy
{
public:
    virtual int do_tactic(int id) = 0;
    std::string toString() const
    {
        return "GameStrategy";
    }
};

class MovementStrategy
{
public:
    virtual int do_move(int x_acceleration, int y_acceleration) = 0;
    std::string toString() const
    {
        return "MovementStrategy";
    }
};
