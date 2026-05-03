#include "game.h"

#include "menu.h"
#include "player_camera.h"
#include "video.h"

#include <time.h>
#include <raylib.h>

Game game_init(GameConfig conf) {
    Game g = {
        .config = conf,
        .running = true,
        .pause_menu = pause_menu_new(),
        .player_camera = player_camera_new(),
        .video = video_new(conf.video_conf),
        .audio = audio_new(),
    };
    
    return g;
}

void game_open(Game* g) {
    // Video init
    video_init(&g->video);

    // Audio init
    audio_init(&g->audio);


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
        
    audio_close(&g->audio);
    video_close(&g->video);
}

void game_update(Game* g) {
    if (WindowShouldClose()) g->running = false;

    bool paused = g->pause_menu.paused;

    if (IsKeyPressed(KEY_ESCAPE)) {
        paused = pause_menu_toggle(&g->pause_menu);
        player_camera_set_grab(&g->player_camera, !paused);
    }

    if (IsKeyPressed(KEY_F11)) {
        video_toggle_fullscreen(&g->video);
    }

    if (!paused) {
        // UpdateCamera(&g->player_camera.camera, CAMERA_FIRST_PERSON);
        player_camera_update(&g->player_camera);
        player_camera_freemove(&g->player_camera);
    }
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

    pause_menu_draw(&g->pause_menu);

    DrawFPS(0, 0);
    EndDrawing();
}

