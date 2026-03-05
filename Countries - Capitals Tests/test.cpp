#include "pch.h"
#include "Game.h"

TEST(GameTest, ClassCreation)
{
    Game game;
    ASSERT_NE(&game, nullptr);
}

TEST(GameTest, LoadPairsFromFile)
{
    Game game;

    int result = game.loadFromFile("../../Countries - Capitals Tests/test_capitals.txt", "../../Countries - Capitals Tests/test_countries.txt");

    ASSERT_EQ(0, result);
}

TEST(GameTest, LoadFromInvalidFile)
{
    Game game;

    int result = game.loadFromFile("wrong.txt", "wrong.txt");

    ASSERT_NE(0, result);
}

TEST(GameTest, LoadFromFile)
{
    Game game;

    int result = game.loadFromFile("../../Countries - Capitals Tests/test_capitals.txt", "../../Countries - Capitals Tests/test_countries.txt");
    ASSERT_EQ(result, 0);

    auto pairs = game.getPairs();
    ASSERT_EQ(pairs.size(), 3);

    ASSERT_EQ(pairs[0].capital, "Париж");
    ASSERT_EQ(pairs[0].country, "Франция");

    ASSERT_EQ(pairs[1].capital, "Берлин");
    ASSERT_EQ(pairs[1].country, "Германия");

    ASSERT_EQ(pairs[2].capital, "Рим");
    ASSERT_EQ(pairs[2].country, "Италия");
}

TEST(GameTest, ShufflePair)
{
    Game game;
    game.loadFromFile("../../Countries - Capitals Tests/test_capitals.txt", "../../Countries - Capitals Tests/test_countries.txt");

    game.shufflePairs();

    std::vector<CountryCapital> seen;
    for (size_t i = 0; i < game.getPairs().size(); ++i)
    {
        auto p = game.getNextPair();
        seen.push_back(p);
    }

    auto original = game.getPairs();
    ASSERT_EQ(seen.size(), original.size());

    for (const auto& p : original)
    {
        bool found = false;
        for (const auto& s : seen)
        {
            if (p.capital == s.capital && p.country == s.country) {
                found = true;
                break;
            }
        }
        ASSERT_TRUE(found);
    }
}

TEST(GameTest, CheckAnswer)
{
    Game game;
    game.loadFromFile("../../Countries - Capitals Tests/test_capitals.txt", "../../Countries - Capitals Tests/test_countries.txt");

    auto pairs = game.getPairs();

    ASSERT_TRUE(game.checkAnswer(pairs[0], "Париж", true));
    ASSERT_TRUE(game.checkAnswer(pairs[0], "Франция", false));

    ASSERT_FALSE(game.checkAnswer(pairs[0], "Берлин", true));
    ASSERT_FALSE(game.checkAnswer(pairs[0], "Германия", false));
}