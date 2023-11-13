#include "AgentBody.hpp"
#include <iostream>
#include <vector>

class Solver {
    private:
    // List of agents:
    std::vector<AgentBody*> agents;

    // Constructor
    Solver() {
        std::cout << "Solver constructor" << std::endl;
    }

    // Destructor
    ~Solver() {
        std::cout << "Solver destructor" << std::endl;
    }

    public:

    // Singleton
    static Solver& getInstance() {
        static Solver instance;
        return instance;
    }

    // Copy constructor and assignment operator
    Solver(Solver const&) = delete;
    void operator=(Solver const&) = delete;

    void update() {
        std::cout << "Solver update" << std::endl;
        update_agents();
        wall_collisions();
    }
    void update_agents() {
        for (auto agent : agents) {
            agent->update_position();
        }
    }

    void wall_collisions() {
        for (auto agent : agents) {
            if (agent->get_x_position() < 0) {
                agent->set_x_position(0);
            }
            if (agent->get_y_position() < 0) {
                agent->set_y_position(0);
            }
            if (agent->get_x_position() > 10) {
                agent->set_x_position(10);
            }
            if (agent->get_y_position() > 10) {
                agent->set_y_position(10);
            }
        }
    }



    void add_agent(AgentBody* agent) {
        agents.push_back(agent);
    }
};