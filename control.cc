#include "control.h"

Control::Control(Game& game): m_game(game) {}

void Control::handleKeyPress(char key) {
    auto it = KEYMAP.find(key);
    if (it != KEYMAP.end()) {
        m_game.setSnakeDirection(it->second);
    }
}

const std::map<char, Snake::Direction> Control::KEYMAP  = {
    {'w', Snake::Direction::UP},
    {'a', Snake::Direction::LEFT},
    {'s', Snake::Direction::DOWN},
    {'d', Snake::Direction::RIGHT}
};
