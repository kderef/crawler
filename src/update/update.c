#include "prelude.h"
#include "game.h"

void game_update(Game* game) {
    // update state
    game->quit ^= WindowShouldClose();

    switch (game->state) {
        case GAME_MAIN_MENU:
            
            break;
    }
}
