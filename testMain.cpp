// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <string>
// #include <cstdlib>
// #include <ctime>
// #include <algorithm>
// #include "Agent.hpp"
// #include "Game.hpp"
// #include "History.hpp"
// #include "GameStrategies/GameStrategyList.hpp"
// #include "MovementStrategies/MovementStrategyList.hpp"
// // #include "StrategyInitializer.cpp"


// int main()
// {

//     // Initailize history
//     History& history = History::getInstance();

//     // Initialize game
//     Game& game = Game::getInstance();

//     // Create a DumbTitfortat and a Defect agent

//     // DumbTitfortat
//     Agent *agent1 = new Agent(0);
//     agent1->set_strategy(new DumbTitForTat());
//     // Defect
//     Agent *agent2 = new Agent(1);
//     agent2->set_strategy(new Defect());

//     // Play 1 game
//     int result = game.play_game(agent1->play(), agent2->play());
//     std::cout << "Result: " << result << std::endl;

//     // update scores
    

//     // Add to history
//     int hash = history.hash(1, agent1->get_id(), agent2->get_id());
//     history.add(hash, result);
//     history.update_recent_history(agent1->get_id(), hash);
//     history.update_recent_history(agent2->get_id(), hash);
//     // Play 2nd game
//     result = game.play_game(agent1->play(), agent2->play());
//     std::cout << "Result: " << result << std::endl; // should be 3

//     // test that agent scores are updating
//     std::cout << "Agent 1 score: " << agent1->get_score() << std::endl;
//     std::cout << "Agent 2 score: " << agent2->get_score() << std::endl;

//     // make a new agent
//     Agent *agent3 = new Agent(2);
    
//     // Test all setters
//     agent3->set_strategy(new Defect());
//     agent3->set_strategy(new RandomMove());
//     agent3->set_score(10);
//     agent3->set_x_position(5);
//     agent3->set_y_position(5);

//     // Test all getters
//     std::cout << "Agent 3 id: " << agent3->get_id() << std::endl;
//     std::cout << "Agent 3 score: " << agent3->get_score() << std::endl;
//     std::cout << "Agent 3 x position: " << agent3->get_x_position() << std::endl;
//     std::cout << "Agent 3 y position: " << agent3->get_y_position() << std::endl;
//     std::cout << "Agent 3 game strategy" << agent3->get_game_strategy() << std::endl;
//     std::cout << "Agent 3 movement strategy" << agent3->get_movement_strategy() << std::endl;
//     std::cout << "Agent 3 game strategy name" << agent3->get_game_strategy_name() << std::endl;
//     std::cout << "Agent 3 movement strategy name" << agent3->get_movement_strategy_name() << std::endl;
    


//     return 0;
// }