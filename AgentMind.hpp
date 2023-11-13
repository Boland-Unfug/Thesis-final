#include "GameStrategies/GameStrategyList.hpp"
#include "MovementStrategies/MovementStrategyList.hpp"
#pragma once

class Agent
{
private:
    GameStrategy *game_strategy;
    MovementStrategy *movement_strategy;

    int id;
    int score = 0;

    int x_position;
    int y_position;
    int previous_x_position;
    int previous_y_position;
    int x_acceleration;
    int y_acceleration;

public:
    Agent(int id) : id(id){}; // Default Constructor
    // Agent(int id, GameStrategy *game_strategy) : id(id), game_strategy(game_strategy){}; // Constructor
    virtual ~Agent(){}; // Destructor

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

    int get_previous_x_position()
    {
        return previous_x_position;
    }

    int get_previous_y_position()
    {
        return previous_y_position;
    }

    int get_x_acceleration()
    {
        return x_acceleration;
    }

    int get_y_acceleration()
    {
        return y_acceleration;
    }

    GameStrategy *get_game_strategy()
    {
        return game_strategy;
    }

    MovementStrategy *get_movement_strategy()
    {
        return movement_strategy;
    }

    std::string get_game_strategy_name()
    {
        return game_strategy->toString();
    }

    std::string get_movement_strategy_name()
    {
        return movement_strategy->toString();
    }

    // Setter function, overwrites the value for the given value.
    void set() {}

    //@see set
    void set_score(int score)
    {
        this->score = score;
    }

    void add_score(int score)
    {
        this->score += score;
    }

    void subtract_score(int score)
    {
        this->score -= score;
    }

    void set_x_position(int x_position)
    {
        this->x_position = x_position;
    }

    void set_y_position(int y_position)
    {
        this->y_position = y_position;
    }

    void set_previous_x_position(int previous_x_position)
    {
        this->previous_x_position = previous_x_position;
    }

    void set_previous_y_position(int previous_y_position)
    {
        this->previous_y_position = previous_y_position;
    }

    void set_x_acceleration(int x_acceleration)
    {
        this->x_acceleration = x_acceleration;
    }

    void set_y_acceleration(int y_acceleration)
    {
        this->y_acceleration = y_acceleration;
    }

    //@see set
    void set_strategy(GameStrategy *game_strategy)
    {
        // check for nullptr
        if (game_strategy == nullptr)
        {
            throw std::invalid_argument("game_strategy cannot be nullptr");
        }
        this->game_strategy = game_strategy;
    }

    //@see set
    void set_strategy(MovementStrategy *movement_strategy)
    {
        if (movement_strategy == nullptr)
        {
            throw std::invalid_argument("movement_strategy cannot be nullptr");
        }

        this->movement_strategy = movement_strategy;
    }

    void set_position(int x, int y)
    {
        x_position = x;
        y_position = y;
    }

    void set_x_position(int x)
    {
        x_position = x;
    }

    void set_y_position(int y)
    {
        y_position = y;
    }

    int play()
    {
        return game_strategy->do_tactic(id);
    }
};