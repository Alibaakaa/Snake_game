#include "view.h"

void View::runGame(Game& game) {
    Control gameControl(game);
    while (isOpen(game)) {
        handleEvents(gameControl);
        drawFrame(game);
    }
}
