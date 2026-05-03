#include "video.h"

#include <raylib.h>

Video video_new(VideoConfig conf) {
    return (Video) {
        .config = conf,
        .fullscreen = conf.fullscreen,
    };
}

void video_init(Video* v) {
    unsigned int flags = 0;

    if (v->config.msaa_4x) flags |= FLAG_MSAA_4X_HINT;
    if (v->config.resizable) flags |= FLAG_WINDOW_RESIZABLE;
    if (v->config.vsync) flags |= FLAG_VSYNC_HINT;
        
    // if(flags...)

    SetConfigFlags(flags);

    // Init window
    
    InitWindow(v->config.width, v->config.height, v->config.title);

    SetExitKey(0);
    SetTargetFPS(v->config.target_fps);

    if (v->config.fullscreen) video_set_fullscreen(v, true);
}

int video_set_fps(Video* v, int fps_target) {
    SetTargetFPS(fps_target);
    return fps_target;
}

bool video_toggle_fullscreen(Video* v) {
    return video_set_fullscreen(v, !v->fullscreen);
}

bool video_set_fullscreen(Video* v, bool fullscreen) {
    if (v->fullscreen != fullscreen) {
        ToggleFullscreen();
        v->fullscreen = fullscreen;
    }
    return fullscreen;
}

void video_close(Video* v) {
    CloseWindow();
}

int video_width() {
    return GetScreenWidth();
}
int video_height() {
    return GetScreenHeight();
}
Vector2 video_size() {
    return (Vector2) { video_width(), video_height() };
}
