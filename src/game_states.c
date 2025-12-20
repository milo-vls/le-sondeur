#include "game_states.h"
#include <raylib.h>

void
update (World *world)
{
        BeginDrawing ();
        switch (world->game_state)
        {
        case GAME_STATE_BASIC_MENU:
                update_basic_menu (&world->basic_menu);
                break;
        case GAME_STATE_PLAY:

                break;
        }
        EndDrawing ();
}
