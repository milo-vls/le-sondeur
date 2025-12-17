#include "basic-menu/title_screen.h"
#include "asset/sprite.h"
#include "basic-menu/basic_menu.h"
#include "dimensions.h"
#include "game_states.h"
#include <raylib.h>

#define TITLE_SCREEN_QUIT_BUTTON_X_POS (GAME_WIDTH / 8.0f * 5.0f)
#define TITLE_SCREEN_QUIT_BUTTON_Y_POS (GAME_HEIGHT / 8.0f * 1.0f)

void
title_screen_quit_game (World *world)
{
        world->game_state = GAME_STATE_BASIC_MENU;
        CloseWindow ();
}

Basic_menu
load_title_screen ()
{
        Basic_menu title_screen = create_basic_menu (GAME_WIDTH, GAME_HEIGHT);

        // quit button
        Vector2 quit_button_position
            = { (float)TITLE_SCREEN_QUIT_BUTTON_X_POS,
                (float)TITLE_SCREEN_QUIT_BUTTON_Y_POS };
        Sprite quit_button_sprite
            = { .texture
                = LoadTexture ("../ressources/button/jouer/jouer_ss.png"),
                .accumulated_time = 0.0f,
                .} Button quit_button
            = (Button){ .position = quit_button_position, .sprite = };

        basic_menu_add_button (, Button button, Button_method button_method,
                               Basic_menu * basic_menu);
        return title_screen;
}
