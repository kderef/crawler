#include "player_camera.h"

#include <math.h>
#include <raylib.h>
#include <raymath.h>

#include <stdint.h>

PlayerCamera player_camera_new() {
    PlayerCamera pc = {
        .fovy = 75.0,
        .position = {1, 0, 1},
        .projection = CAMERA_PERSPECTIVE,
        .target = {2, 1, 2},
        .up = {0, 1, 0},

        .mouse_grabbed = false,

        .yaw = 0,
        .pitch = 0,
        .sensitivity = 100,
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

void player_camera_update(PlayerCamera* pc) {
    const Vector2 m_delta = GetMouseDelta();    

    const float sens = pc->sensitivity * 0.0001;

    pc->yaw   -= m_delta.x * sens;
    pc->pitch -= m_delta.y * sens;

    if (pc->pitch > 1.5) pc->pitch = 1.5;
    if (pc->pitch < -1.5) pc->pitch = -1.5;

    pc->pitch = Clamp(pc->pitch, -1.5, 1.5);

    const Vector3 forward = {
        cosf(pc->pitch) * sinf(pc->yaw),
        sinf(pc->pitch),
        cosf(pc->pitch) * cosf(pc->yaw)
    };

    pc->target = Vector3Add(pc->position, forward);
}
