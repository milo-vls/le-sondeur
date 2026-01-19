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

	game_object cake = init_object ("ressources/models/cake/cake.obj", NULL);
	Texture2D cake_diffuse = LoadTexture("ressources/models/cake/cake_diffuse.png");
	SetMaterialTexture (&cake.model.materials[0], MATERIAL_MAP_DIFFUSE, cake_diffuse);

	game_object test = init_object ("ressources/models/animtest.glb", "ressources/models/animtest.glb");
	
	add_object (&world, cake);
	add_object (&world, test);

	while (!WindowShouldClose ())
        {
                update_world (&world);
        }
	ShowCursor ();
        CloseWindow ();
        return 1;
}
