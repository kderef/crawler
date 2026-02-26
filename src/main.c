#include <stdio.h>

#include "game/game.h"

int main(void) {
    const GameConfig conf = {
        .title = "Hello",
        .width = 800,
        .height = 600,
        .target_fps = 120,
        .resizable = true,
        .vsync = false,

        .fovy = 80.0,
    };
        
    Game g = game_init(conf);

    game_open(&g);
    game_load(&g);

    while (g.running) {
        game_update(&g);
        game_draw(&g);
    }

    game_close(&g);

    return 0;
}
