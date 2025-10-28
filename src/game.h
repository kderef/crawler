#pragma once

struct Game;

#include "settings.h"
#include "prelude.h"

#include "level/level.h"

typedef enum {
    SCENE_MENU = 0,
    SCENE_TEST,
} Scene;

/// The main game instance, initialized by `game_init()`
typedef struct Game {
    bool quit;
    bool show_fps;
    bool paused;

    Scene scene;

    Settings settings;
    Keymap keymap;

    Level current_level;
} Game;

/// Returns true if the game was successfully started.
bool game_init(Game*, const Config*);

/// Close the game and window and unload all data
void game_close(Game*);

/// Update the game state, call before game_draw() at the start of each frame.
void game_update(Game*);

/// Draw the game frame using the data from game_update()
void game_draw(Game*);

/// Load assets and data
void game_load_assets(Game*);

/// Unload assets and data, call before game_close()
void game_unload_assets(Game*);
