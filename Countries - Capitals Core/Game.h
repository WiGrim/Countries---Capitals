#pragma once
#include <string>
#include <vector>

struct CountryCapital {
    std::string country;
    std::string capital;
};

class Game
{
public:
    Game();

    int loadFromFile(const std::string& capitalsFile, const std::string& countriesFile);
    std::vector<CountryCapital> getPairs() const;
private:
    std::vector<CountryCapital> pairs;
};