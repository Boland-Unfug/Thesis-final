#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Agent.hpp"
#include "Game.hpp"
#include "History.hpp"
#include "StrategyInit.cpp"


int main()
{

    // Initailize history
    History& history = History::getInstance();

    // Initialize strategies
    StrategyInitializer* strategy_initializer = new StrategyInitializer();

    std::string gamestrategies = strategy_initializer->getStrategies("GameStrategies");
    std::string movementstrategies = strategy_initializer->getStrategies("MovementStrategies");

    // make a map of strategies, where the key is the name of the strategy and the value is a pointer to the strategy
    std::unordered_map<std::string, GameStrategy *> game_strategy_map = initialize_GameStrategies(gamestrategies);
    

    //
    // // Initialize strategies
    // // std::unordered_map<std::string, MovementStrategy *> movement_strategy_map = initialize_MovementStrategies();
    // // StrategiesList* strategy_map = new StrategiesList();

    // std::srand(std::time(nullptr));

    

    // const int num_agents = 10000;
    // const int num_rounds = 1000000;

    // // Initialize 100 agents
    // Agent *agents[num_agents];
    // for (int i = 0; i < num_agents; i++)
    // {
    //     agents[i] = new Agent(i);
    //     if (i % 2 == 0)
    //     {
    //         agents[i]->set_game_strategy(strategy_map["Cooperate"]);
    //     }
    //     else
    //     {
    //         agents[i]->set_game_strategy(strategy_map["Defect"]);
    //     }
    // }

    // // Initialize game
    // Game game;

    // for (int i = 0; i < num_rounds; i++)
    // {
    //     int player1 = rand() % num_agents;
    //     int player2 = rand() % num_agents;
    //     while (player1 == player2)
    //     { // ensure that the two players are different
    //         player2 = rand() % num_agents;
    //     }
    //     int state = game.play_game(agents[player1]->play(), agents[player2]->play());

    //     // get the scores
    //     std::pair<int, int> scores = game.get_scores(state);

    //     // hash
    //     int hashed = history.hash(0, player1, player2);

    //     // add to history
    //     history.add(hashed, state);
    // }

    // // calculate each agents scores
    // int final_scores[num_agents];
    // for (int i = 0; i < num_agents; i++)
    // {
    //     final_scores[i] = 0;
    // }

    // std::vector<int> keys;

    // // Iterate over the map and extract the keys
    // for (const auto &pair : history.history)
    // {
    //     keys.push_back(pair.first);
    // }

    // // Get the score from each game
    // for (int i = 0; i < keys.size(); i++)
    // {
    //     int player1 = keys[i] >> 16; // These should be a variable TODO
    //     int player2 = keys[i] & 0xFFFF;
    //     int state = history.get(keys[i]);
    //     std::pair<int, int> scores = game.get_scores(state);
    //     final_scores[player1] += scores.first;
    //     final_scores[player2] += scores.second;
    // }

    // // print the top 10 scores, and their games played
    // for (int i = 0; i < 10; i++)
    // {
    //     int max_score = 0;
    //     int max_index = 0;
    //     for (int j = 0; j < num_agents; j++)
    //     {
    //         if (final_scores[j] > max_score)
    //         {
    //             max_score = final_scores[j];
    //             max_index = j;
    //         }
    //     }
    //     std::cout << "Agent " << max_index << " scored " << max_score << std::endl;
    //     final_scores[max_index] = 0;
    // }
    return 0;
}
