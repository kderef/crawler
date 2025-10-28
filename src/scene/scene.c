#pragma once

#include "game.h"
#include "level/level.h"

void scene_transition(Game* game, Scene new_scene) {
    if (new_scene == SCENE_TEST) {
        // load a level
        printf("Creating\n");
        game->current_level = test_level(game);
    }

    game->scene = new_scene;
}
