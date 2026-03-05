#pragma once
#include <string>

class Game
{
public:
    Game();

    int loadFromFile(std::string capitalsFile, std::string countriesFile);
};