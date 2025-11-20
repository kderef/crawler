#include "game/game.h"

int main() {
    Game game;

    while (game.running) {
        game.update();
        game.draw();
    }
}
