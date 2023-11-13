#include "../Strategies.hpp"
#pragma once

// This is dumb tit-for-tat, because it plays the last move of any opponent, not the opponent it is facing
class DumbTitForTat : public GameStrategy
{
private:
    History& history = History::getInstance();
    Game& game = Game::getInstance();

public:
    int do_tactic(int id) // TODO does this mean I need all instances to take an id?
    {
        int last_round = history.get_recent(id); // needed to find the hash of the last round
        int player1, player2, round = history.dehash(last_round); // needed to figure out if agent is player 1
        int state = history.get(last_round);
        std::cout<<"state " << state << std::endl;
        std::cout<<"returning " << ((state == 0 || state == 3 || (state == 2 && id > player1)) ? 1 : 0) << std::endl;

        return ((state == 0 || state == -1) || state == 3 || (state == 2 && id > player1)) ? 1 : 0;
    }
    std::string toString() const {
        return "DumbTitForTat";
    }
};