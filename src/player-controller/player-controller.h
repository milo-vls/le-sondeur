#ifndef PLAYER_CONTROLLER_H
#define PLAYER CONTROLLER_H
#include <raylib.h>

#define SPEED 0.6f
#define MOUSE_SENS 0.001f
#define FRICTION 0.8f

typedef struct  
{
	Camera3D cam;
	float yaw;
	float roll;
} Player;

Player init_player();
void update_player(Player* p);

#endif
