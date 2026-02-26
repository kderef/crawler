#include "game.h"

#include <time.h>
#include <raylib.h>
#include <stdio.h>

Game game_init(GameConfig conf) {
    Game g = {
        .config = conf,
        .running = true,
        .camera = (Camera3D) {
            .position = {1, 1, 1},
            .target = {0, 0, 0},
            .up = {0, 1, 0},
            .fovy = 80.0,
            .projection = CAMERA_PERSPECTIVE,
        }
    };

    unsigned int flags = 0;

    if (conf.resizable) flags |= FLAG_WINDOW_RESIZABLE;
    if (conf.vsync) flags |= FLAG_VSYNC_HINT;

    SetConfigFlags(flags);
    
    return g;
}

void game_open(Game* g) {
    GameConfig* c = &g->config;
        
    InitWindow(c->width, c->height, c->title);
    InitAudioDevice();

    SetExitKey(0);
    SetTargetFPS(c->target_fps);
    SetRandomSeed(time(0));
}

void game_close(Game* g) {
    CloseAudioDevice();
    CloseWindow();
}

void game_update(Game* g) {
    if (WindowShouldClose()) g->running = false;

    UpdateCamera(&g->camera, CAMERA_ORBITAL);
}

void game_draw(Game* g) {
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(g->camera);
    {
        DrawGrid(10, 1.0);

        DrawCube(
            (Vector3){0.0, 0.5, 0.0},
            0.5,
            0.5,
            0.5,
            RED
        );
    }
    EndMode3D();

    DrawFPS(0, 0);
    EndDrawing();
}

