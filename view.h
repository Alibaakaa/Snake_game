#pragma once

#include "game.h"

#include <utility>

class View {
public:
    virtual std::pair<int, int> getSize() const = 0;
    virtual ~View() = default;

    void runGame(Game& game);

protected:
    virtual bool isOpen() const = 0;
    virtual void handleEvents() = 0;
    virtual void drawFrame() = 0;
};
 