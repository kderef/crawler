#include <stdio.h>
#include <stdbool.h>
#include "raylib.h"

#define MEM_DEBUG // tracking allocations

#include "assets.c"
#include "util.c"
#include "mem.c"
#include "log.c"

int main(void) {
    // setup logging
    if (!log_file_open("log.txt")) {
        ERROR("Failed to open log: %s", strerror(errno));
    }
    SetTraceLogCallback(tracelog_callback);

    // -- init raylib
    uint flags = FLAG_MSAA_4X_HINT;

    SetConfigFlags(flags);
    InitWindow(800, 600, "hello world");

    SetTargetFPS(120);
    SetExitKey(KEY_NULL);

    // -- load all stuff
    if (!assets_load("assets")) {
        ERROR("Failed to load assets");
        return 1;
    }
    InitAudioDevice();

    bool run = true;
    bool draw_fps = true;

    while (run) {
        run ^= WindowShouldClose();

        BeginDrawing();
        ClearBackground(BLACK);

        if (draw_fps) DrawFPS(0, 0);
        EndDrawing();
    }
    

    assets_unload();

    CloseAudioDevice();
    CloseWindow();

    log_file_close();

    return 0;
}
