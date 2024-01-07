/*
** Example of hot-reloading game functions.
** Raylib code based on the core 3d camera example.
**
** Based on:
** - https://medium.com/@TheElkantor/how-to-add-hot-reload-to-your-raylib-proj-in-c-698caa33eb74
** - https://github.com/ddovod/jet-live
**
 */

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#include "raylib.h"
#include "debug.h"
#include "reload.h"
#include "game.h"

int dbg = 1;

init_gamestate_t init_gamestate = NULL;
free_gamestate_t free_gamestate = NULL;
update_gamestate_t update_gamestate = NULL;
update_frame_t update_frame = NULL;

gamestate_t *state = NULL;

int do_reload() {
    static symtab_t symtab[] = {
        {"init_gamestate", (void **)&init_gamestate},
        {"free_gamestate", (void **)&free_gamestate},
        {"update_gamestate", (void **)&update_gamestate},
        {"update_frame", (void **)&update_frame},
        {0}
    };
    return reload("game.so", symtab);
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    if (do_reload() != 0) {
        return 1;
    };

    state = init_gamestate();

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera mode");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        if (IsKeyPressed(KEY_R))
            do_reload();

        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        update_gamestate(state);


        // Draw
        //----------------------------------------------------------------------------------
        update_frame(state);
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


    free_gamestate(state);
    state = NULL;

    return 0;
}
