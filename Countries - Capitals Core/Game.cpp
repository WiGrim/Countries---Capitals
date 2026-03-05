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

void Game::shufflePairs()
{
    randomizedIndices.clear();
    for (size_t i = 0; i < pairs.size(); ++i)
        randomizedIndices.push_back(i);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(randomizedIndices.begin(), randomizedIndices.end(), gen);

    currentIndex = 0;
}

CountryCapital Game::getNextPair()
{
    if (currentIndex >= randomizedIndices.size())
        return { "", "" };

    return pairs[randomizedIndices[currentIndex++]];
}

bool Game::checkAnswer(const CountryCapital& pair, const std::string& userAnswer, bool byCapital)
{
    if (byCapital)
        return userAnswer == pair.capital;
    else
        return userAnswer == pair.country;
}

std::vector<CountryCapital> Game::getPairs() const
{
    return pairs;
}