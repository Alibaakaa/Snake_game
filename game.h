#pragma once

#include "snake.h"

#include <algorithm>
#include <list>
#include <random>
#include <utility>

class Game {
public:
    Game(int width, int height);

    void update();
    void setSnakeDirection(Snake::Direction direction);
    bool isAlive() const;
    
private:
    Snake m_snake;
    std::list<std::pair<int, int>> m_rabbits;
    mutable std::mt19937 m_randomGenerator;
    int m_width;
    int m_height;
    bool m_snakeHasEaten;
    bool m_snakeAlive;

    std::pair<int, int> getRandomCoordinate() const;

    static const int START_RABBITS = 5;
};
