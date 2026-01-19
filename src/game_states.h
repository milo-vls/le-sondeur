#ifndef GAME_STATES_H
#define GAME_STATES_H
#include "game_objects.h"
#include "player-controller/player-controller.h"
#include "basic-menu/basic_menu.h"
#include "utils-and-ds/linked_list.h"
#include <raylib.h>

typedef enum GAME_STATE
{
        GAME_STATE_BASIC_MENU,
        GAME_STATE_PLAY
} GAME_STATE;

typedef struct World
{
        GAME_STATE game_state;
        Basic_menu basic_menu;
	Player player;
	
	size_t object_count;
	game_object* objects;
} World;

World init_world ();
void draw_world (World *world);
void update_world (World *world);
void add_object(World *world, game_object object); 

#endif
