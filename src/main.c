#include <stdio.h>
#include <stdbool.h>
#include "raylib.h"

int main(void) {
    // setup
    InitWindow(800, 600, "hello world");

    SetTargetFPS(120);
    SetExitKey(KEY_NULL);

    bool run = true;

    while (run) {
        run ^= WindowShouldClose();

        BeginDrawing();

        EndDrawing();
    }
    

    CloseWindow();

    return 0;
}
