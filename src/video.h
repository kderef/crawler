#pragma once

#include <raylib.h>

typedef struct {
    const char* title;
    int target_fps;
    
    int width;
    int height;

    bool vsync;
    bool fullscreen;
    bool msaa_4x;
    bool resizable;
} VideoConfig;

typedef struct {
    VideoConfig config;

    bool fullscreen;
} Video;

Video video_new(VideoConfig);

void video_init(Video*);
void video_close(Video*);

int video_set_fps(Video*, int);
bool video_toggle_fullscreen(Video*);
bool video_set_fullscreen(Video*, bool);

int video_width();
int video_height();
Vector2 video_size();
