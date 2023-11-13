#include "World.hpp"
#include "Agent.hpp"

int main()
{
    int agent_num = 10;
    int round_num = 10;

    World* world = new World();

    world->set_num_rounds(round_num);

    std::vector<Agent*> agents;
    for (int i = 0; i < agent_num; i++)
    {

        Agent* agent = new Agent(i);

        switch (i % 3)
        {

        case 0:
            agent->set_strategy(new Defect());
            break;
        case 1:
            agent->set_strategy(new Cooperate());
            break;
        case 2:
            agent->set_strategy(new RandomMove());
            break;

        agents.push_back(agent);
    }

    // for (int i = 0; i < agent_num; i++)
    // {
    //     switch (i%2)
    //     {
    //         case 0:
    //             agents[i]->set_strategy(new Left());
    //             break;
    //         case 1:
    //             agents[i]->set_strategy(new Cooperate());
    //             break;
    //     }
    // }
    world->set_agents(agents, agent_num);
    


    
    return 0;
}
}