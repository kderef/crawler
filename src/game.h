#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <stdbool.h>

#include "skybox.h"
#include "player_camera.h"
#include "menu.h"

/******************************************************************************/
// game


typedef struct {
    const char* title;
    int width, height;
    
    int target_fps;
    bool vsync;
    bool resizable;
    bool msaa_4x;

    float fovy;
} GameConfig;

typedef struct {
    GameConfig config;
    bool running;

    // UI
    PauseMenu pause_menu;
        
    // camera system
    PlayerCamera player_camera;
    Skybox skybox;

    Texture tex_test1;
} Game;

Game game_init(GameConfig);
void game_load(Game*);

void game_open(Game*);
void game_close(Game*);

// loop

void game_update(Game*);
void game_draw(Game*);



#endif // GAME_H
