#include "tview.h"

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <poll.h>
#include <string>

Tview::Tview(): m_isOpen(true) {
    tcgetattr(0, &m_stateBuffer);
    termios raw = m_stateBuffer;
    cfmakeraw(&raw);
    tcsetattr(0, TCSANOW, &raw);
}

Tview::~Tview() {
    clear();
    tcsetattr(0, TCSANOW, &m_stateBuffer);
    printf("Goodbye!\n");
}

std::pair<int, int> Tview::getSize() const {
    winsize win_size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win_size);
    return { win_size.ws_col, win_size.ws_row };
}

bool Tview::isOpen() const {
    return m_isOpen;
}

void Tview::handleEvents(Control& control) {
    pollfd event{ 0, POLLIN, 0 };
    while (m_isOpen && poll(&event, 1, 0) == 1) {
        char keyPressed;
        read(0, &keyPressed, 1);
        if (keyPressed == 'q') {
            m_isOpen = false;
            break;
        }
        control.handleKeyPress(keyPressed);
    }
}

void Tview::drawFrame(Game& game) {
    game.update();
    if (!game.isAlive()) m_isOpen = false;
    auto [width, height] = getSize();

    clear();
    drawSnake(game);
    drawRabbits(game);
    move(height, width);
    fflush(stdout);
}

void Tview::drawSnake(const Game& game) {
    static std::string HEAD[4] = {"⤊", "⤋", "⇚", "⇛"};
    bool isHead = true;
    Snake::Direction dir = game.getSnakeDirection();
    for (auto [x, y] : game.getSnakeBody()) {
        std::string sym = isHead ? HEAD[static_cast<int>(dir)] : "◉";
        printf("\e[%d;%dH\e[96m%s", y, x, sym.c_str());
        isHead = false;
    }
}

void Tview::drawRabbits(const Game& game) {
    for (auto [x, y] : game.getRabbits()) {
        printf("\e[%d;%dH\e[96m🐇", y, x);
    }
}

void Tview::move(int x, int y) {
    std::cout << "\e[" << x << ";" << y << "H";
}

void Tview::clear() {
    printf("\e[1;1H \e[J");
}
