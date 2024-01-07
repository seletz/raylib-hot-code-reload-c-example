#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "debug.h"

#include "raylib.h"
#include "game.h"

gamestate_t * init_gamestate() {
    gamestate_t *state = malloc(sizeof(gamestate_t));

    state->tick = 0LL;
    state->camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    state->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    state->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    state->camera.fovy = 45.0f;                                // Camera field-of-view Y
    state->camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    state->cubePosition = (Vector3){ 0.0f, 0.0f, 0.0f };

    return state;
}

int free_gamestate(gamestate_t *state) {
    assert(state);
    free(state);
    return 0;
}

int update_gamestate(gamestate_t *state) {
    assert(state);

    state->tick += 1;

    return 0;
}


int update_frame(gamestate_t *state) {
    assert(state);

    BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(state->camera);

            DrawCube(state->cubePosition, 2.0f, 2.0f, 2.0f, GREEN);
            DrawCubeWires(state->cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

            DrawGrid(100, 1.0f);

        EndMode3D();

        DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);
        char buf[80];
        snprintf(buf, 80, "TICK %lld", state->tick);
        DrawText(buf, 10, 60, 20, DARKGRAY);

        DrawFPS(10, 10);

    EndDrawing();

    return 0;
}
