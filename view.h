#pragma once

#include "control.h"
#include "game.h"

#include <utility>

class View {
public:
    virtual std::pair<int, int> getSize() const = 0;
    virtual ~View() = default;

    void runGame(Game& game);

protected:
    virtual bool isOpen(Game& game) const = 0;
    virtual void handleEvents(Control& control) = 0;
    virtual void drawFrame(Game& game) = 0;
};
 