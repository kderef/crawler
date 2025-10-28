#include "game.h"
#include "level.h"

Level test_level(Game* game) {
    Level level = {0};

    level.width = 2;
    level.height = 2;

    level.rooms[0] = (Room) { 0 };
    level.rooms[1] = (Room) { 0 };
    level.rooms[2] = (Room) { 0 };
    level.rooms[3] = (Room) { 0 };

    return level;
}

