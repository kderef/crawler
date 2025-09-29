#pragma once

#include "settings.h"
#include "prelude.h"

/// The main game instance, initialized by `game_init()`
typedef struct {
    bool quit;
    bool show_fps;
    bool paused;

    Settings settings;
    Keymap keymap;
} Game;

/// Returns true if the game was successfully started.
bool game_init(Game*, const Config*);

/// Close the game and window and unload all data
void game_close(Game*);

/// Update the game state, call before game_draw() at the start of each frame.
void game_update(Game*);

/// Draw the game frame using the data from game_update()
void game_draw(Game*);
