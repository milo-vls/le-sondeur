#ifndef GAME_STATES_H
#define GAME_STATES_H

#include "linked_list.h"
#include "sprite.h"

typedef enum GAME_STATE
{
        GAME_STATE_TITLE_SCREEN,
} GAME_STATE;

typedef struct World
{
        GAME_STATE game_state;
        Linked_list layers;
} World;


void draw_game (World *world);
void update (World *world);

//--- BASIC_MENU ---//
#define MAX_NUMBER_OF_BUTTONS 50

typedef struct  
{
        Vector2 position;
        Sprite sprite;
} Button;

bool point_in_button (Button *button, Vector2 point_position);
bool button_clicked (Button *button);


typedef struct 
{
        int pressed_button_index;
        Button buttons[MAX_NUMBER_OF_BUTTONS];
} Basic_menu;

void update_basic_menu(Basic_menu *basic_menu);




#endif
