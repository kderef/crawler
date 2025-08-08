#include <stdio.h>
#include <stdbool.h>
#include "raylib.h"

#include "log.c"

int main(void) {
    // setup logging
    if (!log_file_open("log.txt")) {
        ERROR("Failed to open log: %s", strerror(errno));
    }
    SetTraceLogCallback(tracelog_callback);

    // setup
    InitWindow(800, 600, "hello world");

    SetTargetFPS(120);
    SetExitKey(KEY_NULL);



    bool run = true;
    bool draw_fps = true;

    while (run) {
        run ^= WindowShouldClose();

        BeginDrawing();
        ClearBackground(BLACK);

        if (draw_fps) DrawFPS(0, 0);
        EndDrawing();
    }
    

    CloseWindow();

    return 0;
}
