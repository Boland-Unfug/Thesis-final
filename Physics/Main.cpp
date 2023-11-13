#include "Solver.hpp"


main() {

    // create an agent
    AgentBody* agent = new AgentBody();

    // set position, velocity, and acceleration
    agent->set_x_position(0);
    agent->set_y_position(0);
    agent->set_previous_x_position(0);
    agent->set_previous_y_position(0);
    agent->set_x_acceleration(3);
    agent->set_y_acceleration(3);

    // add the agent to the solver
    Solver::getInstance().add_agent(agent);

    // print the agent's position
    std::cout << "Agent position: (" << agent->get_x_position() << ", " << agent->get_y_position() << ")" << std::endl;

    // update the solver
    Solver::getInstance().update();

    // print the agent's position
    std::cout << "Agent position: (" << agent->get_x_position() << ", " << agent->get_y_position() << ")" << std::endl;

    // update the solver
    Solver::getInstance().update();

    // print the agent's position
    std::cout << "Agent position: (" << agent->get_x_position() << ", " << agent->get_y_position() << ")" << std::endl;

    // set the agent's acceleration to -3
    agent->set_x_acceleration(-3);
    agent->set_y_acceleration(-3);

    // update the solver
    Solver::getInstance().update();

    // print the agent's position
    std::cout << "Agent position: (" << agent->get_x_position() << ", " << agent->get_y_position() << ")" << std::endl;

    // update the solver
    Solver::getInstance().update();

    // print the agent's position
    std::cout << "Agent position: (" << agent->get_x_position() << ", " << agent->get_y_position() << ")" << std::endl;
   return 0;

}