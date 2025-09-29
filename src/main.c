#include "prelude.h"
#include "config.h"
#include <raylib.h>

#include "game.c"

int main(int argc, char** argv) {
    // ignore
    (void)argc;
    (void)argv;

    Config config = {
        .resizable = true,
        .hidpi = true,
        .msaa_4x = true,
        .vsync = false,
        .init_width = 800,
        .init_height = 600,
        .window_title = "crawler"
    };
    
    Game game = {0};

    game_init(&game, &config);

    while (!game.quit) {
        game_update(&game);
        game_draw(&game);
    }

    game_close(&game);

    return 0;
}
