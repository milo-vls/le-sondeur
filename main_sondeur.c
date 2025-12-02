#include "layer.h"
#include "linked_list.h"
#include <raylib.h>
#include <stdlib.h>

#define GAME_WIDTH 800
#define GAME_HEIGHT 800

typedef enum GAME_STATE
{
        GAME_STATE_TITLE_SCREEN,
} GAME_STATE;

typedef struct World
{
        GAME_STATE game_state;
} World;

void
update (World *world)
{
        BeginDrawing ();
        ClearBackground (PURPLE);
        EndDrawing ();
}

int
main (void)
{
        InitWindow (GAME_WIDTH, GAME_HEIGHT, "Le sondeur.");
        SetTargetFPS (60);
        World world = { .game_state = GAME_STATE_TITLE_SCREEN };

        Linked_list layers = { sizeof (Layer), NULL };
        Layer *gui_layer_ptr = (Layer *)(malloc (sizeof (Layer)));
        *gui_layer_ptr
            = (Layer){ 0, LoadRenderTexture (GAME_WIDTH, GAME_HEIGHT) };
        add_layer (&layers, gui_layer_ptr);

        while (!WindowShouldClose ())
        {
                update (&world);
        }
        CloseWindow ();
        return 1;
}
