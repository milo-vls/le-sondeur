#ifndef GAME_STATES_H
#define GAME_STATES_H

#include "basic-menu/basic_menu.h"
#include <raylib.h>

typedef enum GAME_STATE
{
        GAME_STATE_BASIC_MENU,
} GAME_STATE;

typedef struct World
{
        GAME_STATE game_state;
        Basic_menu basic_menu;
} World;

void draw_game (World *world);
void update (World *world);

#endif
