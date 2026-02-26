#include "game.h"
#include <raylib.h>
#include <stdio.h>

Game game_init(void) {
    printf("Hello\n");
    Game g = {};

    InitWindow(800, 600, "a");
    
    return g;
}
