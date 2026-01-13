#include "player-controller/player-controller.h"
#include <raylib.h>
#include <raymath.h>


Player init_player()
{
	Player p = {0};
	
	p.cam = (Camera3D){
  		.position = (Vector3) {-30.f, 10.f, 0.f},
  		.target = (Vector3) {0.f, 0.f, 0.f},
  		.fovy = 60,
  		.up = (Vector3) {0.f, 1.f, 0.0f},
  		.projection = CAMERA_PERSPECTIVE
	};
	
	return p;
}

void update_player(Player* p)
{

	float deltaTime = GetFrameTime();

	Vector2 mouse_pos = GetMousePosition();

	mouse_pos.x -=  GetScreenWidth() / 2; mouse_pos.y -= GetScreenHeight() / 2;

        if(mouse_pos.y != 0) p->roll -= mouse_pos.y * MOUSE_SENS;
        if(p->roll > PI/2) p->roll = PI/2;
        if(p->roll < -PI/2) p->roll = -PI/2;

        if(mouse_pos.x != 0) p->yaw -= mouse_pos.x * MOUSE_SENS;
        if(p->yaw > 2*PI) p->yaw = 0;
        else if(p->yaw < 0 ) p->yaw = 2*PI;
	
	SetMousePosition(GetScreenWidth() / 2, GetScreenHeight() / 2);

	if(IsKeyDown(KEY_RIGHT)) p->yaw -= 0.1f;
	if(IsKeyDown(KEY_LEFT)) p->yaw += 0.1f;
	if(IsKeyDown(KEY_DOWN)) p->roll -= 0.1f;
	if(IsKeyDown(KEY_UP)) p->roll += 0.1f;

	if(IsKeyDown(KEY_W)) p->cam.position = Vector3Add(p->cam.position, Vector3RotateByAxisAngle((Vector3){SPEED + deltaTime, 0, 0}, (Vector3){0, 1, 0}, p->yaw));
	if(IsKeyDown(KEY_S)) p->cam.position = Vector3Add(p->cam.position, Vector3RotateByAxisAngle((Vector3){SPEED + deltaTime, 0, 0}, (Vector3){0, 1, 0}, p->yaw - PI));
	if(IsKeyDown(KEY_A)) p->cam.position = Vector3Add(p->cam.position, Vector3RotateByAxisAngle((Vector3){SPEED + deltaTime, 0, 0}, (Vector3){0, 1, 0}, p->yaw + PI/2));
	if(IsKeyDown(KEY_D)) p->cam.position = Vector3Add(p->cam.position, Vector3RotateByAxisAngle((Vector3){SPEED + deltaTime, 0, 0}, (Vector3){0, 1, 0}, p->yaw - PI/2));
	
	if(IsKeyDown(KEY_SPACE)) p->cam.position.y += SPEED;
	if(IsKeyDown(KEY_C)) p->cam.position.y -= SPEED;

	Vector3 target = Vector3RotateByAxisAngle(Vector3RotateByAxisAngle((Vector3){1, 0, 0}, (Vector3){0, 0, 1}, p->roll), (Vector3){0, 1, 0}, p->yaw);

	p->cam.target = Vector3Add(p->cam.position, target);
}
