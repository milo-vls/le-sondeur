#include "utils-and-ds/linked_list.h"
#include "game_states.h"
#include <stdlib.h>
#include <raylib.h>

World
init_world ()
{
        return (World){ 
			.player = init_player (), 
			.object_count = 0, 
			.objects = (game_object*)malloc(sizeof(game_object)) };
}


void
update_world (World *world)
{
        switch (world->game_state)
        {
        case GAME_STATE_BASIC_MENU:
		BeginDrawing ();
			ClearBackground (BLANK);
			update_basic_menu (&world->basic_menu, world);
                break;
        case GAME_STATE_PLAY:
		update_player (&world->player);
		for(size_t i = 0; i < world->object_count; i++) update_object (&world->objects[i]);
		BeginDrawing ();
			ClearBackground (BLANK);
			BeginMode3D(world->player.cam);
			for(size_t i = 0; i < world->object_count; i++) DrawModelEx (world->objects[i].model, (Vector3) world->objects[i].position, world->objects[i].rotation_axis, world->objects[i].rotation_angle, world->objects[i].scale, WHITE);
			EndMode3D();
                break;
        }
        EndDrawing ();
}

void 
add_object (World *world, game_object object)
{
	world->object_count++;
	world->objects = (game_object*)realloc(world->objects, world->object_count * sizeof(object));
	world->objects[world->object_count-1] = object;
}
