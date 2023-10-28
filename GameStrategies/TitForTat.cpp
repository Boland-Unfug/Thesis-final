#include "Strategies.hpp"


class TitForTatStrategy : public GameStrategy
{
private:
    History& history = History::getInstance();
    Game& game = Game::getInstance();

public:
    int do_tactic(int id) // TODO does this mean I need all instances to take an id?
    {
        int last_round = history.get_recent(id); // needed to find the hash of the last round
        int player1, player2, round = history.dehash(last_round); // needed to figure out if agent is player 1
        int last_state = history.get(last_round); // needed to figure out their move
        std::pair<int,int> move = game.get_moves(last_state); // needed to figure out their moves
        
        //find which player matches id
        if (player1 == id){
            //return player 2's move
            return move.second;
        }
        else{
            //return player 1's move
            return move.first;
        }
    }
};