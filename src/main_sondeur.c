#include "utils-and-ds/linked_list.h"
#include "basic-menu/title_screen.h"
#include "dimensions.h"
#include "game_states.h"
#include <raylib.h>


int
main (void)
{
        InitWindow (GAME_WIDTH, GAME_HEIGHT, "Le sondeur.");
        SetTargetFPS (60);
        SetWindowFocused ();
        World world = init_world ();

	world.game_state = GAME_STATE_BASIC_MENU;
        world.basic_menu = load_title_screen ();

	Model cake = LoadModel ("ressources/models/cake/cake.obj");

	Texture2D diffuse = LoadTexture("ressources/models/cake/cake_diffuse.png");
	SetMaterialTexture(&cake.materials[0], MATERIAL_MAP_DIFFUSE, diffuse);

        add_model(&world, cake);

	while (!WindowShouldClose ())
        {
                update_world (&world);
        }
	ShowCursor ();
        CloseWindow ();
        return 1;
}
