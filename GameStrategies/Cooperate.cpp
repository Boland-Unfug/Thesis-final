#pragma once
#include "Strategies.hpp"

class CooperateStrategy : public GameStrategy
{
public:
    int do_tactic(int id)
    {
        return 1;
    }
};