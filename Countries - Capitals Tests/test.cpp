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

    int result = game.loadFromFile("test_capitals.txt", "test_countries.txt");

    ASSERT_EQ(0, result);
}

TEST(GameTest, LoadFromInvalidFile)
{
    Game game;

    int result = game.loadFromFile("wrong.txt", "wrong.txt");

    ASSERT_NE(0, result);
}