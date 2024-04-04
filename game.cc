#include "game.h"

Game::Game(int width, int height)
    : m_width(width), m_height(height), m_snake(width / 2, height / 2) {
    std::random_device randomDevice;
    m_randomGenerator.seed(randomDevice());

    for (int i = 0; i < START_RABBITS; ++i) {
        auto [x, y] = getRandomCoordinate();
        m_rabbits.emplace_back(x, y);
    }
}

void Game::update() {
    auto [headX, headY] = m_snake.move(m_snakeHasEaten);
    if (m_snake.eatsItself() || headX < 0 || headX >= m_width || headY < 0 || headY >= m_height) {
        m_snakeAlive = false;
    }
    m_snakeHasEaten = false;
    auto it = std::find(m_rabbits.begin(), m_rabbits.end(), { headX, headY });
    if (it != m_rabbits.end()) {
        m_snakeHasEaten = true;
        m_rabbits.erase(it);
    }
}

void Game::setSnakeDirection(Snake::Direction direction) {
    m_snake.setDirection(direction);
}

bool Game::isAlive() const {
    return m_snakeAlive;
}

const std::list<std::pair<int, int>>& Game::getSnakeBody() const {
    return m_snake.getBody();
}

const std::list<std::pair<int, int>>& Game::getRabbits() const {
    return m_rabbits;
}

Snake::Direction Game::getSnakeDirection() const {
    return m_snake.getDirection();
}

std::pair<int, int> Game::getRandomCoordinate() const {
    std::uniform_int_distribution widthDistrib(0, m_width - 1);
    std::uniform_int_distribution heightDistrib(0, m_height - 1);
    return { widthDistrib(m_randomGenerator), heightDistrib(m_randomGenerator) };
}
