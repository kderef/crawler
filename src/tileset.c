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

void tileset_unload() {
    INFO("unloading tileset");
    UnloadTexture(tileset.texture);
}
