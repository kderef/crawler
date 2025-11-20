#pragma once

#include <raylib.h>

class Game {
public:
    bool running = true;

    Game();
    ~Game();

    void update();
    void draw();
};
