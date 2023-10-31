#include "../Strategies.hpp"

// This is dumb tit-for-tat, because it plays the last move of any opponent, not the opponent it is facing
class TitForTat : public GameStrategy
{
private:
    History& history = History::getInstance();
    Game& game = Game::getInstance();

public:
    int do_tactic(int id) // TODO does this mean I need all instances to take an id?
    {
        int reversed_move = 1;
        int last_round = history.get_recent(id); // needed to find the hash of the last round
        int player1, player2, round = history.dehash(last_round); // needed to figure out if agent is player 1
        int state = history.get(last_round);
        if (state == 2 || state == 3){
            if ()
        }
        if (id > player1) {

        }

        
        
        
        


        // ok, we can understand that game states 0 and 3 just return the same move (since its a mirror)
        // if its 0, return 1
        // if its 3, return 0
        // otherwise, see if the agent id is higher than player 1.
        // If it is, then the agent is player 2, so return the first move.
        // If it isn't, then the agent is player 1, so return the second move.
    }
};