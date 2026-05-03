#include "game.h"
#include "src/player_camera.h"

#include <time.h>
#include <raylib.h>

Game game_init(GameConfig conf) {
    Game g = {
        .config = conf,
        .running = true,
        .paused = false,
        .player_camera = player_camera_new(),
    };

    unsigned int flags = 0;

    if (conf.resizable) flags |= FLAG_WINDOW_RESIZABLE;
    if (conf.vsync) flags |= FLAG_VSYNC_HINT;
    if (conf.msaa_4x) flags |= FLAG_MSAA_4X_HINT;

    SetConfigFlags(flags);
    
    return g;
}

void game_open(Game* g) {
    const GameConfig* c = &g->config;
        
    InitWindow(c->width, c->height, c->title);
    InitAudioDevice();

    SetExitKey(0);
    SetTargetFPS(c->target_fps);
    SetRandomSeed(time(0));

    // grab cursor
    player_camera_set_grab(&g->player_camera, true);
}

void game_load(Game* g) {
    Image img_test1 = LoadImage("textures/skybox_test1.png");
    g->tex_test1 = LoadTextureFromImage(img_test1);
    g->skybox = skybox_generate(img_test1);
    UnloadImage(img_test1);
}

void game_close(Game* g) {
    skybox_unload(&g->skybox);

    player_camera_set_grab(&g->player_camera, false);
        
    CloseAudioDevice();
    CloseWindow();
}

void game_update(Game* g) {
    if (WindowShouldClose()) g->running = false;

    UpdateCamera(&g->player_camera.camera, CAMERA_FIRST_PERSON);
}

void game_draw(Game* g) {
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(g->player_camera.camera);
    {
        skybox_draw(&g->skybox);
        
        DrawGrid(10, 1.0);

        DrawCube(
            (Vector3){0.0, 0.5, 0.0},
            0.5,
            0.5,
            0.5,
            RED
        );
    }
    EndMode3D();

    DrawFPS(0, 0);
    EndDrawing();
}

