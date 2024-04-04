#include "game.h"
#include "tview.h"

#include <memory>

int main() {
    // TODO: replace with view selection
    std::unique_ptr<View> view(new Tview());

    auto [width, height] = view->getSize();
    Game game(width, height);
    view->runGame(game);
    
    return 0;
}
