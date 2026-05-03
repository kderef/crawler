#include "player_camera.h"
#include "raylib.h"

PlayerCamera player_camera_new() {
    PlayerCamera pc = {
        .fovy = 75.0,
        .position = {1, 0, 1},
        .projection = CAMERA_PERSPECTIVE,
        .target = {2, 1, 2},
        .up = {0, 1, 0},
        .mouse_grabbed = false
    };

    return pc;
}

void player_camera_set_grab(PlayerCamera* pc, bool grab) {
    if (grab == pc->mouse_grabbed) return;

    if (grab) {
        HideCursor();
        DisableCursor();
    }
    else {
        ShowCursor();
        EnableCursor();
    }

    pc->mouse_grabbed = grab;
}
