#include <iostream>
#include <filesystem>

class StrategyInitializer
{
public:
    std::string getStrategies(std::string strategy_location)
    {
        std::string strategies = "";
        const std::string folderPath = "./" + strategy_location; // Replace with the path to the folder you want to read
        const std::string targetExtension = ".cpp";              // The extension you are looking for

        try
        {
            for (const auto &entry : std::filesystem::directory_iterator(folderPath))
            {
                if (entry.path().extension() == targetExtension)
                {
                    std::string path = entry.path().string();
                    std::cout << path << std::endl;
                    strategies += path + " ";
                }
            }
        }
        catch (std::filesystem::filesystem_error &e)
        {
            std::cerr << e.what() << std::endl;
        }
        return strategies;
    }

    
};
