#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <stdbool.h>

#include "skybox.h"
#include "player_camera.h"
#include "menu.h"
#include "video.h"
#include "audio.h"

/******************************************************************************/
// game


typedef struct {
    VideoConfig video_conf;
} GameConfig;

typedef struct {
    GameConfig config;
    bool running;

    // systems
    Video video;
    Audio audio;

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
