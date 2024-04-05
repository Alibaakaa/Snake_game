#pragma once

#include "view.h"

#include <termios.h>

class Tview: public View {
public:
    Tview();
    ~Tview() override;

    std::pair<int, int> getSize() const override;

protected:
    bool isOpen() const override;
    void handleEvents(Control& control) override;
    void drawFrame(Game& game) override;

private:
    bool m_isOpen;
    termios m_stateBuffer;

    void clear();
    void drawSnake(const Game& game);
    void drawRabbits(const Game& game);
};
