#include "dimensions.h"
#include "game_states.h"
#include <raylib.h>

World
init_wolrd ()
{

        return (World){ .game_state = GAME_STATE_BASIC_MENU };
}

int
main (void)
{
        InitWindow (GAME_WIDTH, GAME_HEIGHT, "Le sondeur.");
        SetTargetFPS (60);
        World world = init_wolrd ();
        while (!WindowShouldClose ())
        {
                update (&world);
        }
        CloseWindow ();
        return 1;
}
