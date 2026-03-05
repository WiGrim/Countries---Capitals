#include "pch.h"
#include "Game.h"

Game::Game()
{
}

int Game::loadFromFile(std::string capitalsFile, std::string countriesFile)
{
    std::ifstream capitals(capitalsFile);
    std::ifstream countries(countriesFile);

    if (!capitals.is_open() || !countries.is_open())
        return 1;

    //todo загрузка данных

    return 0;
}