#include "raylib.h"
#include "config.h"
#include <sys/types.h>

typedef struct {
    bool quit;
    bool show_fps;
    bool paused;
} Game;

bool game_init(Game* game, const Config* conf) {
    uint flags = config_flags(conf);
    
    SetConfigFlags(flags);

    InitWindow(800, 600, "crawler");
    SetExitKey(0);
    SetTargetFPS(120);
    
    InitAudioDevice();

    return true;
}

void game_close(Game* game) {
    
        CloseAudioDevice();
        CloseWindow();
}

void game_update(Game* restrict game) {
    
    // update state
    game->quit ^= WindowShouldClose();
}

void game_draw(Game* restrict game) {
    
    BeginDrawing();
    ClearBackground(BLACK);

    if (game->show_fps)
        DrawFPS(0, 0);
    EndDrawing();
}


