#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include "raylib.h"

#define MEM_DEBUG // tracking allocations
#define LOG_TIMESTAMP

#include "game.c"
#include "tileset.c"
#include "assets.c"
#include "util.c"
#include "mem.c"
#include "log.c"

int init() {
    // setup logging
    SetTraceLogCallback(tracelog_callback);
    if (!log_file_open("log.txt")) {
        ERROR("Failed to open log: %s", strerror(errno));
    }

    // -- init raylib
    uint flags = FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE;

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

    return 0;
}

void close() {
    assets_unload();

    CloseAudioDevice();
    CloseWindow();

    log_file_close();
}

int main(void) {
    int exit_code = 0;

    // -- 1: Initialise
    exit_code = init();
    if (exit_code != 0) goto shutdown;
    
    // -- 2: Game state
    bool run = true;
    bool draw_fps = true;

    // -- 3: Game loop
    while (run) {
        run ^= WindowShouldClose();

        BeginDrawing();
        ClearBackground(BLACK);

        assets_test();

        if (draw_fps) DrawFPS(0, 0);
        EndDrawing();
    }

    // 4: Game shutdown & cleanup
    
shutdown:
    close();
    return exit_code;
}
