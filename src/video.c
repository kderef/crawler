#include "video.h"

#include <raylib.h>

Video video_init(int width, int height, const char* title) {
    
    SetExitKey(0);

    return (Video) {
        .screen_w = width,
        .screen_h = height,
        .title = title,

        .fullscreen = false,
        .vsync = false,
    };
}

void video_set_fps(Video* v, int fps_target) {
    SetTargetFPS(fps_target);
}

void video_close(Video* v) {
    CloseWindow();
}
