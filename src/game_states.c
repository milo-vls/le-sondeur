#include "utils-and-ds/linked_list.h"
#include "game_states.h"
#include <stdlib.h>
#include <raylib.h>

World
init_world ()
{
        return (World){ 
			.player = init_player (), 
			.model_count = 0, .model_capacity = 1,
			.models = (Model*)malloc(sizeof(Model)) };
}


void
update_world (World *world)
{
        BeginDrawing ();
        ClearBackground (BLANK);
        switch (world->game_state)
        {
        case GAME_STATE_BASIC_MENU:
                update_basic_menu (&world->basic_menu, world);
                break;
        case GAME_STATE_PLAY:
		update_player (&world->player);
		BeginMode3D(world->player.cam);
		for(size_t i = 0; i < world->model_count; i++) DrawModel(world->models[i], (Vector3) {0.0f, 0.0f, 0.0f}, 1, WHITE);
		EndMode3D();
                break;
        }
        EndDrawing ();
}

void 
add_model (World *world, Model model)
{
	if(world->model_count >= world->model_capacity)
	{
		world->model_capacity *= 2;
		world->models = (Model*)realloc(world->models, world->model_capacity * sizeof(Model));
	}
	world->models[world->model_count] = model;
	world->model_count++;
}
