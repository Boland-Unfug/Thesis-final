// #include <iostream>
// #include <filesystem>
// #include <GameStrategies/Cooperate.cpp>
// #include <GameStrategies/Defect.cpp>
// #include <GameStrategies/Random.cpp>
// #include <GameStrategies/TitForTat.cpp

// class StrategyInitializer
// {
// public:
//     std::string getStrategies(std::string strategy_location)
//     {
//         std::string strategies = "";
//         const std::string folderPath = "./" + strategy_location; // Replace with the path to the folder you want to read
//         const std::string targetExtension = ".cpp";              // The extension you are looking for

//         try
//         {
//             for (const auto &entry : std::filesystem::directory_iterator(folderPath))
//             {
//                 if (entry.path().extension() == targetExtension)
//                 {
//                     std::string path = entry.path().string();
//                     std::cout << path << std::endl;
//                     strategies += path + " ";
//                 }
//             }
//         }
//         catch (std::filesystem::filesystem_error &e)
//         {
//             std::cerr << e.what() << std::endl;
//         }
//         return strategies;
//     }

//     std::unordered_map<std::string, Strategy*> initializeStrategies () {
//         // for now we can just hardcode the strategies
//         std::unordered_map<std::string, Strategy*> strategy_map;
//         strategy_map["Cooperate"] = new Cooperate();
//         strategy_map["Defect"] = new Defect();
//         strategy_map["Random"] = new Random();
//         strategy_map["TitForTat"] = new GameStrategy.TitForTat();
        
//     }

//     /*
//     std::cout << "Initializing strategies" << std::endl;
//         // extract the strategy names from the string
//         std::vector<std::string> strategy_paths;
//         std::string strategy_path = "";
//         for (int i = 0; i < (strategies.length()) - 1; i++) {
//             if (strategies[i] == ' ') {
//                 strategy_paths.push_back(strategy_path);
//                 strategy_path = "";
//             } else {
//                 strategy_path += strategies[i];
//             }
//         }

//         strategy_paths.push_back(strategy_path);

//         // remove everything that is not a strategy name by finding the last '/' and ., getting their position, and doing a slice
//         std::cout << "Removing strategy paths" << std::endl;
//         std::vector<std::string> strategy_names;
//             std::string strategy_name = "";
//             std::string strategy_path = "";
//             int last_slash = 0;
//             // I only need to do this once because all the strategy paths are the same length
//             for (int j = 0; j < strategy_paths[0].length(); j++) {
//                 if (strategy_paths[0][j] == '\\') {
//                     last_slash = j;
//                 }
//             }

//             for (int i = 0; i < strategy_paths.size(); i++) {
                
//                 strategy_paths[i] = strategy_paths[i].substr(last_slash + 1, strategy_paths[i].length() - 5 - last_slash);
//             }
            
//             strategy_names.push_back(strategy_name);

//         // initialize the strategies
//         std::cout << "Initializing strategy map" << std::endl;
//         std::unordered_map<std::string, Strategy*> strategy_map;
//         for (int i = 0; i < strategy_paths.size(); i++) {
//             std::cout << "Initializing " << strategy_paths[i] << std::endl;
//             std::string strategy_name = strategy_paths[i];
//             strategy_map[strategy_name] = new Strategy(strategy_name);
//         }
//         return strategy_map;
//     */
// };
