#include "snake.h"

Snake::Snake(int x, int y): m_body{ {x, y} }, m_direction(Direction::DOWN) {}

bool Snake::eatsItself() const {
    return std::find(std::next(m_body.begin()), m_body.end(), m_body.front()) != m_body.end();
}

void Snake::setDirection(Direction direction) {
    m_direction = direction;
}

std::pair<int, int> Snake::move(bool hasEaten) {
    auto [dx, dy] = DIRECTIONS[static_cast<int>(m_direction)];
    auto [headX, headY] = m_body.front();
    m_body.emplace_front(headX + dx, headY + dy);
    if (!hasEaten) m_body.pop_back();
}

const std::list<std::pair<int, int>>& Snake::getBody() const {
    return m_body;
}

Snake::Direction Snake::getDirection() const {
    return m_direction;
}
