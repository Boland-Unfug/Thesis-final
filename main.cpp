#include <iostream>
#include <unordered_map>
#include <vector>
#include "Agent.hpp"
#include "Game.hpp"
#include "History.hpp"

int main()
{
    // //Generate two agents
    // Agent* c = new CooperateAgent(0);
    // Agent* d = new DefectAgent(1);

    // // play game
    // Game game;

    // // get the game state
    // int state = game.play_game(c->play(), d->play());

    // // get the scores
    // std::pair<int, int> scores = game.get_scores(state);

    // // print the scores
    // std::cout << scores.first << " " << scores.second << std::endl;

    // // add to history
    // History history;
    // int player1_id = c->get_id();
    // int player2_id = d->get_id();

    // // hash
    // int hashed = history.hash(0, player1_id, player2_id);
    // std::cout << hashed << std::endl;

    // // add to history
    // history.add(hashed, state);

    // // get from history
    // int retrieved_state = history.get(hashed);

    // Initailize history
    History history;

    const int num_agents = 100;
    const int num_rounds = 30000;

    // Initialize 100 agents
    Agent *agents[num_agents];
    for (int i = 0; i < num_agents; i++)
    {
        if (rand() % 2 == 0)
        {
            agents[i] = new CooperateAgent(i);
        }
        else
        {
            agents[i] = new DefectAgent(i);
        }
    }

    // Initialize game
    Game game;

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

        // hash
        int hashed = history.hash(0, player1, player2);

        // add to history
        history.add(hashed, state);
    }

    // calculate each agents scores
    int final_scores[num_agents];
    for (int i = 0; i < num_agents; i++)
    {
        final_scores[i] = 0;
    }

    std::vector<int> keys;

    // Iterate over the map and extract the keys
    for (const auto& pair : history.history) {
        keys.push_back(pair.first);
    }

    // Get the score from each game
    for (int i = 0; i < keys.size(); i++)
    {
        int player1 = keys[i] >> 8;
        int player2 = keys[i] & 0xFF;
        int state = history.get(keys[i]);
        std::pair<int, int> scores = game.get_scores(state);
        final_scores[player1] += scores.first;
        final_scores[player2] += scores.second;
    }

    // print the top 10 scores, and their games played
    for (int i = 0; i < 10; i++)
    {
        int max_score = 0;
        int max_index = 0;
        for (int j = 0; j < num_agents; j++)
        {
            if (final_scores[j] > max_score)
            {
                max_score = final_scores[j];
                max_index = j;
            }
        }
        std::cout << "Agent " << max_index << " scored " << max_score << std::endl;
        final_scores[max_index] = 0;
    }
}