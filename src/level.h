#pragma once

#include <stdbool.h>

#define level_null_depth (-1)
#define level_width 256
#define level_depth 8

typedef struct aabb aabb_t;
typedef struct entity entity_t;
typedef struct tile tile_t;

bool level_init(bool new_level);
void level_quit();
void level_tick(float dt, const aabb_t* aabb);
void level_each_entity(void (*callback)(const entity_t* entity, void* data), const aabb_t* aabb, void *data);
void level_each_tile(void (*callback)(const tile_t* tile, int x, int z, void* data), const aabb_t* aabb, void *data);