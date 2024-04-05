#include "view.h"

void View::runGame(Game& game) {
    Control gameControl(game);
    while (isOpen()) {
        handleEvents(gameControl);
        drawFrame(game);
    }
}
