#include "History.hpp"
#include "Game.hpp"

#pragma once

class GameStrategy
{
public:
    virtual int do_tactic(int id) = 0;
};

class MovementStrategy
{
public:
    virtual void do_move() = 0;
};
