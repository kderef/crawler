#include "prelude.h"

#include "settings.h"

#include <raylib.h>

unsigned config_flags(const Config* conf) {
    unsigned flags = 0;

    if (conf->resizable) flags |= FLAG_WINDOW_RESIZABLE;
    if (conf->high_dpi) flags |= FLAG_WINDOW_HIGHDPI;
    if (conf->msaa_4x) flags |= FLAG_MSAA_4X_HINT;
    if (conf->vsync) flags |= FLAG_VSYNC_HINT;

    return flags;
}

static const Keymap KEYMAP_DEFAULT = {
    .dbg_show_fps = KEY_F10,
    .fullscreen = KEY_F11,

    // movement
    .move_forward = KEY_W,
    .move_back = KEY_S,
    .move_left = KEY_A,
    .move_right = KEY_D
};


static const Settings SETTINGS_DEFAULT = {
    .target_fps = 60,
    
    .vsync = false,
    .msaa_4x = true,
    
    .screen_w = 800,
    .screen_h = 600,

    .keymap = KEYMAP_DEFAULT,
};

void settings_load_default(Settings* settings) {
    int monitor = GetCurrentMonitor();

    int monitor_w = GetMonitorWidth(monitor);
    int monitor_h = GetMonitorHeight(monitor);
    int monitor_refresh = GetMonitorRefreshRate(monitor);

    settings->screen_w = monitor_w;
    settings->screen_h = monitor_h;
    settings->target_fps = monitor_refresh;
}

void settings_copy_config(Settings* settings, const Config* conf) {
    settings->vsync = conf->vsync;
    settings->msaa_4x = conf->msaa_4x;
}
