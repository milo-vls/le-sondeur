#include "game_objects.h"
#include <raylib.h>
#include <stdio.h>
#include <stddef.h>

game_object 
init_object (char *model_path, char *anim_path, char *vs_path, char *fs_path) 
{
	game_object object = {0};
	object.material_count = 0;
	
	object.position = (Vector3){0.0, 0.0, 0.0};
	object.scale = (Vector3){1.0, 1.0, 1.0};
	object.rotation_axis = (Vector3){0.0, 1.0, 0.0};
	object.rotation_angle = 0;

	object.model = LoadModel (model_path);
	
	if(anim_path != NULL) 
	{
		object.anims_count = 0; object.frame_count = 0;
    		object.anims = LoadModelAnimations(anim_path, &object.anims_count);
	} else	object.anims = NULL;
	
	if(vs_path != NULL && fs_path != NULL) 
	{
		object.model.materials[0].shader = LoadShader(vs_path, fs_path);	
	} else	object.model.materials[0].shader = LoadShader("ressources/shaders/default.vs", "ressources/shaders/default.fs");

	return object;
}

void
update_object (game_object* object) 
{
	if(object->anims == NULL) return;
	object->frame_count = ( object->frame_count +1 ) % object->anims[0].frameCount;
	UpdateModelAnimation(object->model, object->anims[0], object->frame_count);
}
