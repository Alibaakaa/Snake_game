#include "view.h"
#include <thread>

void View::runGame(Game& game) {
    Control gameControl(game);
    while (isOpen()) {
        handleEvents(gameControl);
        drawFrame(game);
        using namespace std::literals::chrono_literals;
        std::this_thread::sleep_for(500ms);
    }
}
