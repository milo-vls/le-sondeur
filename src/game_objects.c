#include "game_objects.h"
#include <stdio.h>
#include <stddef.h>

game_object 
init_object (char *model_path, char *anim_path) 
{
	game_object object = {0};
	object.model = LoadModel (model_path);
	if(anim_path != NULL) 
	{
		printf("animation loaded\n");
		object.anims_count = 0; object.frame_count = 0;
    		object.anims = LoadModelAnimations(anim_path, &object.anims_count);
	} else	object.anims = NULL;

	return object;
}

void
update_object (game_object* object) 
{
	if(object->anims == NULL) return;
	printf("object updated %d %d\n", object->anims_count, object->frame_count);
	object->frame_count++;
	UpdateModelAnimation(object->model, object->anims[0], object->frame_count);
	if(object->frame_count >= object->anims[0].frameCount ) object->frame_count = 0;
}
