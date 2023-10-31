#include "Agent.hpp"
#include "Game.hpp"

class Solver
{
    private:
        Solver()
        {
            std::cout << "Solver constructor" << std::endl;
        }

        ~Solver()
        {
            std::cout << "Solver destructor" << std::endl;
        }

    public:

        static Solver &getInstance()
        {
            static Solver instance;
            return instance;
        }

        Solver(Solver const &) = delete;
        void operator=(Solver const &) = delete;

};
