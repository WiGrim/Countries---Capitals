#include "pch.h"
#include "Game.h"

Game::Game()
{
}

int Game::loadFromFile(const std::string& capitalsFile, const std::string& countriesFile)
{
    pairs.clear();

    std::ifstream capFile(capitalsFile);
    std::ifstream couFile(countriesFile);

    if (!capFile.is_open() || !couFile.is_open()) return 1;

    std::string capLine, couLine;
    while (std::getline(capFile, capLine) && std::getline(couFile, couLine))
    {
        if (!capLine.empty() && capLine.back() == '\n')
            capLine.pop_back();
        if (!couLine.empty() && couLine.back() == '\n')
            couLine.pop_back();

        pairs.push_back({ couLine, capLine });
    }

    return 0;
}

std::vector<CountryCapital> Game::getPairs() const
{
    return pairs;
}