#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <raylib.h>

typedef struct game_object {
	Model model;
	ModelAnimation *anims;
	int anims_count;
	int frame_count;
} game_object;

game_object
init_object (char* , char*);

void
update_object (game_object*);

#endif
