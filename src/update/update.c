#include "prelude.h"
#include "game.h"

void game_update(Game* game) {
    // update state
    game->quit ^= WindowShouldClose();

    switch (game->scene) {
        case SCENE_MENU:
            break;
    }
}
