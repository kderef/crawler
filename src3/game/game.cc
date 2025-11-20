#include "game.hh"
#include "raylib.h"

int monitor_refresh() {
    const int monitor = GetCurrentMonitor();

    
}

Game::Game() {
    unsigned flags = FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE;

    SetConfigFlags(flags);
    
    InitWindow(800, 600, "crawler");

    SetExitKey(0);
    SetTargetFPS(120);
}

Game::~Game() {
    CloseWindow();
}
