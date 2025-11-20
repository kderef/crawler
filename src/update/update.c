#include "prelude.h"
#include "game.h"

#include "scene/main_menu/update.c"
#include "scene/test/update.c"

void game_update(Game* game) {
    // update state
    game->quit ^= WindowShouldClose();

    switch (game->scene) {
        case SCENE_MENU:
            break;
        case SCENE_TEST:
            break;
    }
}
