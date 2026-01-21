#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <raylib.h>

typedef struct game_object {
	Model model;
	int material_count;
	ModelAnimation *anims;
	int anims_count;
	int frame_count;

	Vector3 position, scale, rotation_axis;
	float rotation_angle;
} game_object;

game_object
init_object (char *model_path, char *anim_path, char *vs_path, char *fs_path);

void
update_object (game_object* object);

#endif
