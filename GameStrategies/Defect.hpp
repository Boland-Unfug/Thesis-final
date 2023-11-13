#include "../Strategies.hpp"

class Defect : public GameStrategy
{
public:
    int do_tactic(int id)
    {
        return 0;
    }
    std::string toString() const
    {
        return "Defect";
    }
};