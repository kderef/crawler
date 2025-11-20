//#define LOG_DISABLE
#include "log.c"
#include "game.h"

int main(int argc, char** argv) {
    // ignore
    (void)argc;
    (void)argv;

    Config config = {
        .resizable = true,
        .high_dpi = true,
        .msaa_4x = true,
        .vsync = false,
        .fullscreen =false,
        .init_width = 800,
        .init_height = 600,
        .window_title = "crawler"
    };

    // open the logging file
    if (!log_open_file("log.txt")) {
        perror("Failed to open log file");
    }
    else {
        log_hook_raylib();
    }
    
    Game game = {0};

    game_init(&game, &config);
    game_load_assets(&game);

    while (!game.quit) {
        game_update(&game);
        game_draw(&game);
    }

    game_unload_assets(&game);
    game_close(&game);

    log_close_file();

    return 0;
}
