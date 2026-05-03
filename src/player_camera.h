#pragma once

#include <raylib.h>

typedef struct {
    union {
        // Camera3D fields accessible
        struct {
            Vector3 position;       
            Vector3 target;         
            Vector3 up;             
            float fovy;             
            int projection;         
        };
        Camera3D camera;
    };

    bool mouse_grabbed;
} PlayerCamera;

PlayerCamera player_camera_new();
void player_camera_set_grab(PlayerCamera*, bool);

