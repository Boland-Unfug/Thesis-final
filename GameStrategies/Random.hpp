#include "../Strategies.hpp"

class Random : public GameStrategy
{
public:
    int do_tactic(int id)
    {
        return rand() % 2;
    }
};