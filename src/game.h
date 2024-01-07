#ifndef _GAME_H
#define _GAME_H 1

#include "raylib.h"

typedef struct {
    unsigned long long tick;
    Camera3D camera;
    Vector3 cubePosition;
} gamestate_t;


typedef gamestate_t * (*init_gamestate_t)();
typedef int (*free_gamestate_t)(gamestate_t *state);
typedef int (*update_gamestate_t)(gamestate_t *state);
typedef int (*update_frame_t)(gamestate_t *state);

#endif
