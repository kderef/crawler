#pragma once

#include <raylib.h>

typedef struct {
    const char* title;
    
    int screen_w;
    int screen_h;

    bool vsync;
    bool fullscreen;
} Video;

Video video_init(int width, int height, const char* title);
void video_close(Video*);

void video_set_fps(Video*, int);
