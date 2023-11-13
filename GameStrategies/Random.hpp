#include "../Strategies.hpp"

class RandomTactic : public GameStrategy
{
public:
    int do_tactic(int id)
    {
        return rand() % 2;
    }

        std::string toString() const
    {
        return "Random";
    }
};