#include "game.h"
#include "prelude.h"
#include "raylib.h"

void scene_test_draw(Game* game) {
    static Camera3D camera = {
        .position = {0},
        .target = {1, 0, 1},
        .up = {0, 1, 0},
        .fovy = 90,
        .projection = CAMERA_PERSPECTIVE
    };
    

    BeginMode3D(camera);

    DrawGrid(100, 10.);


    EndMode3D();
}
