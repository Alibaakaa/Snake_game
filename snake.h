#pragma once

#include <algorithm>
#include <list>
#include <utility>

class Snake {
public:
    enum class Direction {
        UP = 0,
        DOWN = 1,
        LEFT = 2,
        RIGHT = 3,
    };

    Snake(int x, int y);

    bool eatsItself() const;
    void setDirection(Direction direction);

    std::pair<int, int> move(bool hasEaten);

    const std::list<std::pair<int, int>>& getBody() const;
    Direction getDirection() const;

private:
    std::list<std::pair<int, int>> m_body;
    Direction m_direction;

    static constexpr std::pair<int, int> DIRECTIONS[] = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}
    };
};
