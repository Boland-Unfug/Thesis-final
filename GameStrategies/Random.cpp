#pragma once
#include "Strategies.hpp"

class RandomStrategy : public GameStrategy
{
public:
    int do_tactic(int id)
    {
        return rand() % 2;
    }
};