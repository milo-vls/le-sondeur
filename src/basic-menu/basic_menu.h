#ifndef SONDEUR_BASIC_MENU_H
#define SONDEUR_BASIC_MENU_H

#include "asset/sprite.h"
#include <raylib.h>

#define MAX_NUMBER_OF_BUTTONS 25
#define BASIC_MENU_NO_BUTTON_HOVERED -1

typedef enum BASIC_MENU_DEPTHS
{
        BACKGROUND_MENU_DEPTH = 0,

        TITLE_SCREEN_MENU_DEPTH,

        FOREGROUND_MENU_DEPTH,
        NB_BASIC_MENU_DEPTHS
} BASIC_MENU_DEPTHS;

typedef struct
{
        BASIC_MENU_DEPTHS depth;
        int index;
} Button_index;

typedef struct
{
        int hovered_button_index;
        int pressed_button_index;
        int clicked_button_index;
} Button_state;

typedef struct
{
        Vector2 position;
        Sprite sprite;
        Sprite sprite_hovered;
} Button;
typedef struct World World;
typedef void (*Button_method) (World *world);

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
Basic_menu create_basic_menu (int width, int height);
void update_basic_menu (Basic_menu *basic_menu);
void draw_menu_on_screen (Basic_menu *basic_menu);
void unload_basic_menu (Basic_menu *basic_menu);

#endif
