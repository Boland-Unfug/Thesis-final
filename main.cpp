#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Agent.hpp"
#include "Game.hpp"
#include "History.hpp"
#include "GameStrategies/GameStrategyList.hpp"
// #include "StrategyInitializer.cpp"


int main()
{

    // Initailize history
    History& history = History::getInstance();

    const int num_agents = 2;
    const int num_rounds = 2;

    // Initialize 100 agents
    Agent *agents[num_agents];
    for (int i = 0; i < num_agents; i++)
    {
        agents[i] = new Agent(i);

        //make a case for cooperate and tit for tat
        switch (i % 2)
        {
            case 0:
                agents[i]-> set_game_strategy(new Defect);
                break;
            case 1:
                agents[i]-> set_game_strategy(new DumbTitForTat);
                break;
        }

        

        // switch (i % 4)
        // {
        // case 0:
        //     agents[i]->set_game_strategy(new Cooperate());
        //     break;
        // case 1:
        //     agents[i]->set_game_strategy(new Defect());
        //     break;
        // case 2:
        //     agents[i]->set_game_strategy(new Random());
        //     break;
        // case 3:
        //     agents[i]->set_game_strategy(new TitForTat());
        //     break;
        // }
    }

    // Initialize game
    Game &game = Game::getInstance();

    for (int i = 0; i < num_rounds; i++)
    {
        int player1 = rand() % num_agents;
        int player2 = rand() % num_agents;
        while (player1 == player2)
        { // ensure that the two players are different
            player2 = rand() % num_agents;
        }
        int state = game.play_game(agents[player1]->play(), agents[player2]->play());

        // get the scores
        std::pair<int, int> scores = game.get_scores(state);
        // std::cout << "Player " << player1 << " played " << agents[player1]->play() << std::endl;
        agents[player1]->add_score(scores.first);
        // std::cout << "Player" << player1 << " score: " << agents[player1]->get_score() << std::endl;
        agents[player2]->add_score(scores.second);


        // hash
        int hashed = history.hash(i, player1, player2);

        // add to history
        history.add(hashed, state);
    }

    // make an array of agent scores
    int agent_scores[num_agents];
    for (int i = 0; i < num_agents; i++)
    {
        agent_scores[i] = agents[i]->get_score();
    }

    // sort the array from highest to lowest
    std::sort(agent_scores, agent_scores + num_agents, std::greater<int>());

    // print the array
    std::cout << num_agents << " agents" << std::endl;
    for (int i = 0; i < num_agents; i++)
    {
        std::cout << agent_scores[i] << std::endl;
    }
    return 0;
}