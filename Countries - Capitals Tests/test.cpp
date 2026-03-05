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

    ASSERT_EQ(game.pairs.size(), 3);

    auto pairs = game.getPairs();
    ASSERT_EQ(pairs[0].capital, "Париж");
    ASSERT_EQ(pairs[0].country, "Франция");

    ASSERT_EQ(pairs[1].capital, "Берлин");
    ASSERT_EQ(pairs[1].country, "Германия");

    ASSERT_EQ(pairs[2].capital, "Рим");
    ASSERT_EQ(pairs[2].country, "Италия");
}