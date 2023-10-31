#include "GameStrategies/GameStrategyList.hpp"
#include "MovementStrategies/MovementStrategyList.hpp"

class Agent
{
private:
    GameStrategy *game_strategy;
    MovementStrategy *movement_strategy;

    int id;
    int score = 0;

    int x_position;
    int y_position;

public:
    Agent(int id ) : id(id) {}; // Default Constructor
    // Agent(int id, GameStrategy *game_strategy) : id(id), game_strategy(game_strategy){}; // Constructor
    virtual ~Agent(){};       // Destructor

    int get_id()
    {
        return id;
    }

    int get_score()
    {
        return score;
    }

    int get_x_position()
    {
        return x_position;
    }

    int get_y_position()
    {
        return y_position;
    }

    

    //Setter function, overwrites the value for the given value.
    void set(){}

    //@see set
    void set_score(int score){
        this->score = score;
    }

    void add_score(int score) {
        this->score += score;
    }

    //@see set
    void set_game_strategy(GameStrategy *game_strategy)
    {
        // check for nullptr
        if (game_strategy == nullptr)
        {
            throw std::invalid_argument("game_strategy cannot be nullptr");
        }
        this->game_strategy = game_strategy;
    }

    //@see set
    void set_movement_strategy(MovementStrategy *movement_strategy)
    {
        this->movement_strategy = movement_strategy;
    }

    void set_position(int x, int y)
    {
        x_position = x;
        y_position = y;
    }

    void set_x_position (int x)
    {
        x_position = x;
    }

    void set_y_position (int y)
    {
        y_position = y;
    }

    int play()
    {
        return game_strategy->do_tactic(id);
    }

    void move() //This will need to be something eventually
    {
        movement_strategy->do_move();
    }
};