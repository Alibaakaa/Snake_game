#pragma once

#include "game.h"
#include "snake.h"

#include <map>

class Control {
public:
    Control(Game& game);

    void handleKeyPress(char key);

private:
    Game& m_game;

    static const std::map<char, Snake::Direction> KEYMAP;
};
