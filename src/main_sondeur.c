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

	game_object cake = init_object ("ressources/models/cake/cake.obj", NULL, "ressources/shaders/lightning.vs", "ressources/shaders/lightning.fs");
	Texture2D cake_diffuse = LoadTexture("ressources/models/cake/cake_diffuse.png");
	SetMaterialTexture (&cake.model.materials[0], MATERIAL_MAP_DIFFUSE, cake_diffuse);

	float light_dir[3] = {0, -1, -1}, light_col[4] = {1, 1, 1, 1}, ambient_col[4] = {0.2, 0.2, 0.2};
	int light_dir_loc = GetShaderLocation(cake.model.materials[0].shader, "light_dir");
	int light_col_loc = GetShaderLocation(cake.model.materials[0].shader, "light_color");
	int ambient_col_loc = GetShaderLocation(cake.model.materials[0].shader, "ambient_color");
	SetShaderValue(cake.model.materials[0].shader, light_dir_loc, &light_dir, SHADER_UNIFORM_VEC3);
	SetShaderValue(cake.model.materials[0].shader, light_col_loc, &light_col, SHADER_UNIFORM_VEC4);
	SetShaderValue(cake.model.materials[0].shader, ambient_col_loc, &ambient_col, SHADER_UNIFORM_VEC4);
	
	add_object (&world, cake);

	while (!WindowShouldClose ())
        {
		world.objects[0].rotation_angle += 0.7;
                update_world (&world);
        }
	ShowCursor ();
        CloseWindow ();
        return 1;
}
