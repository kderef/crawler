#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <stdbool.h>

typedef struct {
    const char* title;
    int width, height;
    
    int target_fps;
    bool vsync;
    bool resizable;

    float fovy;
} GameConfig;

typedef struct {
    GameConfig config;
    bool running;

    // camera system
    Camera3D camera;
} Game;

Game game_init(GameConfig);

void game_open(Game*);
void game_close(Game*);

// loop

void game_update(Game*);
void game_draw(Game*);

#endif // GAME_H
