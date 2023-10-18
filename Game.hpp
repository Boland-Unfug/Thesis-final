#include <iostream>

class Game
{
public:
    std::pair<int, int> get_scores(int player1, int player2)
    {
        static const std::pair<int, int> lookup_table[2][2] = {
            {{3, 3}, {0, 5}},
            {{5, 0}, {1, 1}}};
        return lookup_table[player1][player2];
    }
    std::pair<int, int> get_scores(int game_state) {
        static const std::pair<int, int> lookup_table[4] = {
            {3, 3},
            {0, 5},
            {5, 0},
            {1, 1}};
        return lookup_table[game_state];
    }

    // I CAN ONLY USE THIS BECAUSE I KNOW THE ORDER OF THE AGENTS, SO I DON'T NEED TO STORE WHICH AGENT HAS WHICH SCORE
    int get_state(int player1, int player2)
    {
        static const int lookup_table[2][2] = {
            {3, 2},
            {1, 0}};
        return lookup_table[player1][player2];
        
    }
    int get_state(std::pair<int, int> scores)
    {
        static const int lookup_table[2][2] = {
            {3, 2},
            {1, 0}};
        return lookup_table[scores.first][scores.second];
    }

    int play_game(int player1, int player2)
    {
        // ensure that player 1 is the player with the lower id
        if (player1 > player2)
        {
            std::swap(player1, player2);
        }

        // get both agents moves
        int player1_move = player1;
        int player2_move = player2;

        // get the game state
        int game_state = get_state(player1_move, player2_move);

        return game_state;
    };
};
