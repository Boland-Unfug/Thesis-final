// #include "Solver.hpp"
// #include "AgentBody.hpp"
// #include "Game.hpp"
// #include <vector>
// #include <iostream>
// #include <math.h>

// class World
// {
// private:
//     int round;
//     int num_agents;
//     int agent_size = 1;
//     int num_rounds;

//     Solver &solver = Solver::getInstance();

//     std::vector<Agent*> agents;


//     int grid_size = 10;


// public:
//     World()
//     {
//         std::cout << "World constructor" << std::endl;
//     }

//     ~World()
//     {
//         std::cout << "World destructor" << std::endl;
//     }

//     // Setters
//     void set_round(int round)
//     {
//         this->round = round;
//     }

//     void set_num_agents(int num_agents)
//     {
//         this->num_agents = num_agents;
//     }

//     void set_num_rounds(int num_rounds)
//     {
//         this->num_rounds = num_rounds;
//     }

//     void set_agent_size(int agent_size)
//     {
//         this->agent_size = agent_size;
//     }

//     void set_agents(std::vector<Agent*> agents, int num_agents)
//     {
//         this->agents = agents;
//         this->num_agents = num_agents;
//     }

//     void add_agents (std::vector<Agent*> agents, int agent_count)
//     {
//         for (int i = 0; i < agent_count; i++)
//         {
//             this->agents.push_back(agents[i]);
//             num_agents++;
//         }
//     }

//     void add_agent(Agent *agent)
//     {
//         this->agents.push_back(agent);
//         num_agents++;
//     }

//     void set_grid_size(int grid_size)
//     {
//         this->grid_size = grid_size;
//     }

    
//     void game_loop()
//     {
//         // place the agents on the map, using their ID as the index
//         for (int i = 0; i < num_agents; i++)
//         {
//             agents[i]->set_position(i % 10, floor(i / 10));
//         }

//         //Print the initial positions of the agents
        
        
//         for (int i = 0; i < num_rounds; i++)
//         {
//             // trigger movement for each agent
//             for (int j = 0; j < num_agents; j++)
//             {
//                 // agents[j]->move(grid, grid_size);
//             }
//         }
//     }
// };