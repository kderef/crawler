#include "game.hh"
#include "raylib.h"

void Game::draw() {
    BeginDrawing();
    ClearBackground(BLACK);


    DrawFPS(0, 0);
    EndDrawing();
}
