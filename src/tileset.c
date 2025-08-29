#pragma once

#include "log.c"
#include "util.c"

#include <raylib.h>

#define TILE_W 8
#define TILE_H 8

typedef struct {
    Texture texture;
    uint width, height;
    uint tile_width, tile_height;
} Tileset;

static Tileset tileset = {
    .tile_width = TILE_W,
    .tile_height = TILE_H,
};

typedef enum {
    TILE_DEBUG = 0,
    TILE_BRICKWALL,
    TILE_BRICKWALL_DARK,

    TILE_MAX,
} Tile;

bool tileset_load() {
    bool ok = true;
       
    const char* texture_path = "sprite/tileset.png";

    INFO("Loading tileset from path '%s'", texture_path);
        
    tileset.texture = LoadTexture(texture_path);

    if (tileset.texture.id == 0) {
        ok = false;
        goto done;
    }

    tileset.width = tileset.texture.width;
    tileset.height = tileset.texture.height;

    INFO("Tileset      size = (%d, %d)", tileset.width, tileset.height);
    INFO("Tileset tile size = (%d, %d)", tileset.tile_width, tileset.tile_height);
         
    //TODO

done:    
    return ok;
}

Rectangle get_tile(Tile idx) {
    Rectangle tile = {
        .width = tileset.tile_width,
        .height = tileset.tile_height,
    };
    
    int x = tileset.tile_width * idx;
    int y = 0;
    if (x > tileset.width) {
        y += tileset.tile_height;
        x %= tileset.tile_width;
    }
    
    // 2 -> (16, 0, 8, 8)
    // 0 -> (0, 0, 8, 8)
    tile.x = x;
    tile.y = y;

    return tile;
}

void tile_draw_rec(Tile tile, Rectangle dest, Color tint) {
    Rectangle src = get_tile(tile);

    DrawTexturePro(
       tileset.texture,
        src,
        dest,
        vec2(0, 0),
        0.0,
        tint
    );
}

void tile_draw(Tile tile, int x, int y, Color tint) {
    tile_draw_rec(
        tile,
        rect(x, y, tileset.tile_width, tileset.tile_height),
        tint
    );
}

void tileset_unload() {
    INFO("unloading tileset");
    UnloadTexture(tileset.texture);
}
