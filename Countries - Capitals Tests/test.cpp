#include "pch.h"
#include "Game.h"

TEST(GameTest, ClassCreation)
{
    Game game;
    ASSERT_NE(&game, nullptr);
}