#include "basic-menu/title_screen.h"
#include "asset/sprite.h"
#include "basic-menu/basic_menu.h"
#include "dimensions.h"
#include "game_states.h"
#include <raylib.h>

void
title_screen_quit_game (World *world)
{
        world->game_state = GAME_STATE_BASIC_MENU;
        CloseWindow ();
}

void
title_screen_play (World *world)
{
        world->game_state = 0;
}

Basic_menu
load_title_screen ()
{
        Basic_menu title_screen = create_basic_menu (GAME_WIDTH, GAME_HEIGHT);

        // quit button
        // Vector2 quit_button_position
            // = { (float)TITLE_SCREEN_QUIT_BUTTON_X_POS,
                // (float)TITLE_SCREEN_QUIT_BUTTON_Y_POS };
        // printf ("Working directory: %s\n", GetWorkingDirectory ());
        // Sprite quit_button_sprite = create_sprite_auto_h_animation (
            // LoadTexture ("ressources/buttons/jouer/jouer_ss.png"), 3, 3);
        // Button quit_button = (Button){ .position = quit_button_position,
                                       // .sprite = quit_button_sprite,
                                       // .sprite_hovered = quit_button_sprite };
        // play button
        Sprite play_button_sprite = create_sprite_auto_h_animation(LoadTexture ("ressources/buttons/jouer/jouer_ss.png"), 3, 3);
        Sprite hovered_play_button_sprite = create_sprite_auto_h_animation( LoadTexture ("ressources/buttons/jouer/jouer_alt_ss.png"), 3, 3);
        Vector2 play_button_position
            = { .x = (float)TITLE_SCREEN_PLAY_BUTTON_X_POS,
                .y = (float)TITLE_SCREEN_QUIT_BUTTON_Y_POS };
        Button play_button = (Button){ .position = play_button_position,
                                       .sprite = play_button_sprite,
                                       .sprite_hovered = hovered_play_button_sprite };

        // basic_menu_add_button (TITLE_SCREEN_MENU_DEPTH, quit_button,
                               // title_screen_quit_game, &title_screen);
        basic_menu_add_button (TITLE_SCREEN_MENU_DEPTH, play_button,
                               title_screen_play, &title_screen);
        return title_screen;
}
