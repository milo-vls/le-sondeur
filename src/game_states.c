#include "game_states.h"
#include "layer.h"

void
draw_game (World *world)
{
        BeginDrawing ();
        ClearBackground (WHITE);
        draw_layers (&world->layers);
        EndDrawing ();
}

void
update (World *world)
{
        clear_layers (&world->layers);
        switch (world->game_state)
        {
        case GAME_STATE_TITLE_SCREEN:

                break;
        }
        draw_game (world);
}
