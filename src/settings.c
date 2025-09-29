#include "prelude.h"

#include "config.h"

#include <raylib.h>

typedef struct {
    u32 target_fps;
    bool vsync;
    bool msaa_4x;

    int screen_w;
    int screen_h;
} Settings;

static Settings settings = {
    .target_fps = 60,
    .vsync = false,
    .msaa_4x = true,
    .screen_w = 800,
    .screen_h = 600,
};

void settings_load_default() {
    int monitor = GetCurrentMonitor();

    int monitor_w = GetMonitorWidth(monitor);
    int monitor_h = GetMonitorHeight(monitor);
    int monitor_refresh = GetMonitorRefreshRate(monitor);

    settings.screen_w = monitor_w;
    settings.screen_h = monitor_h;
    settings.target_fps = monitor_refresh;
}

Settings settings_default() {
    int monitor = GetCurrentMonitor();

    int refresh = GetMonitorRefreshRate(monitor);
    
    return (Settings) {
        .vsync = false,
        .msaa_4x = true,
        .target_fps = refresh,
    };
}

void settings_copy_config(const Config* conf) {
    settings.vsync = conf->vsync;
    settings.msaa_4x = conf->msaa_4x;
}
