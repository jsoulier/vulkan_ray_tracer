#pragma once

#include <stdint.h>

#include "math_ex.h"

typedef enum mesh_type
{
    mesh_type_player_00,

    mesh_type_dirt_00,
    mesh_type_grass_00,
    mesh_type_sand_00,
    mesh_type_tree_00,
    mesh_type_water_00,

    mesh_type_count,
}
mesh_type_t;

typedef enum shader_type
{
    shader_type_composite_frag,
    shader_type_mesh_frag,
    shader_type_mesh_vert,
    shader_type_screen_vert,

    shader_type_count,
}
shader_type_t;

typedef enum compute_pipeline_type
{
    compute_pipeline_type_readback,

    compute_pipeline_type_count,
}
compute_pipeline_type_t;

const char* get_mesh_path(mesh_type_t type);
const char* get_shader_path(shader_type_t type);
const char* get_compute_pipeline_path(compute_pipeline_type_t type);

typedef enum tile_type
{
    tile_type_dirt,
    tile_type_grass,
    tile_type_sand,
    tile_type_tree,
    tile_type_water,

    tile_type_count,
}
tile_type_t;

typedef struct tile
{
    tile_type_t type;
}
tile_t;

typedef enum item_type
{
    item_type_count,
}
item_type_t;

typedef struct item
{
    item_type_t type;
}
item_t;

void tile_init(tile_t* tile, tile_type_t type);
void item_init(item_t* item, item_type_t type);
mesh_type_t tile_get_mesh_type(const tile_t* tile);
mesh_type_t item_get_mesh_type(const item_t* item);
transform_t tile_get_transform(const tile_t* tile, int x, int z);
aabb_t tile_get_aabb(const tile_t* tile, int x, int z);

