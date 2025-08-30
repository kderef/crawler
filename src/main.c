#include "prelude.h"
#include "config.h"
#include <raylib.h>

int main(int argc, char** argv) {
    // ignore
    (void)argc;
    (void)argv;

    uint flags = FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE;

    SetConfigFlags(flags);

    InitWindow(800, 600, WINDOW_TITLE);
  
    bool run = true;
    bool show_fps = true;

    while (run) {
        run ^= WindowShouldClose();

        BeginDrawing();

        if (show_fps) DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
