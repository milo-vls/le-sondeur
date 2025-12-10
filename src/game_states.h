#ifndef GAME_STATES_H
#define GAME_STATES_H

#include "linked_list.h"
#include "sprite.h"
#include <raylib.h>

typedef enum GAME_STATE
{
        GAME_STATE_TITLE_SCREEN,
} GAME_STATE;

typedef struct Basic_menu Basic_menu;

typedef struct World
{
        GAME_STATE game_state;
        Linked_list layers;
        Basic_menu *basic_menu;
} World;

void draw_game (World *world);
void update (World *world);

//--- BASIC_MENU ---//
#define MAX_NUMBER_OF_BUTTONS 25
typedef enum BASIC_MENU_DEPTHS
{
        BACKGROUND_MENU_DEPTH = 0,
        FOREGROUND_MENU_DEPTH,
        NB_BASIC_MENU_DEPTHS
} BASIC_MENU_DEPTHS;

typedef struct
{
        Vector2 position;
        Sprite sprite;
        Sprite sprite_hovered;
} Button;

typedef void (*Button_method) (World *world);

typedef struct
{
        int hovered_button_index;
        int pressed_button_index;
        int clicked_button_index;
} Button_state;
bool point_in_button (Button *button, Vector2 point_position);
bool button_clicked (Button *button);

typedef struct Basic_menu
{
        Button_state button_state;
        unsigned int nb_buttons[NB_BASIC_MENU_DEPTHS];
        RenderTexture2D render_textures[NB_BASIC_MENU_DEPTHS];
        Button buttons[NB_BASIC_MENU_DEPTHS][MAX_NUMBER_OF_BUTTONS];
        Button_method button_method[NB_BASIC_MENU_DEPTHS]
                                   [MAX_NUMBER_OF_BUTTONS];
        RenderTexture2D menu_render;
} Basic_menu;

void basic_menu_add_button (BASIC_MENU_DEPTHS depth, Button button,
                            Button_method button_method,
                            Basic_menu *basic_menu);
Basic_menu *create_basic_menu ();
void update_basic_menu (Basic_menu *basic_menu);

#endif
