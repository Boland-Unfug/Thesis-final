#include "../Strategies.hpp"

class Cooperate : public GameStrategy
{
public:
    int do_tactic(int id)
    {
        return 1;
    }
};