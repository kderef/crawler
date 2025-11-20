#include "game.hh"
#include "raylib.h"

void Game::update() {
    running ^= WindowShouldClose();
}
