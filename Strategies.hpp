#include "History.hpp"
#include "Game.hpp"

#pragma once

class Strategy
{
public:
    virtual int do_strategy() = 0; // Pure virtual function
};

class GameStrategy : public Strategy
{
public:
    virtual int do_tactic(int id) = 0; // Pure virtual function
};

class MovementStrategy : public Strategy
{
public:
    virtual void do_move() = 0; // Pure virtual function
};
