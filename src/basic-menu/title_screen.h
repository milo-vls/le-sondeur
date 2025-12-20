#ifndef BASIC_MENU_TITLE_SCREEN_H
#define BASIC_MENU_TITLE_SCREEN_H

#include "basic-menu/basic_menu.h"

#define TITLE_SCREEN_QUIT_BUTTON_X_POS (GAME_WIDTH / 8.0f * 5.0f)
#define TITLE_SCREEN_QUIT_BUTTON_Y_POS (GAME_HEIGHT / 8.0f * 1.0f)
#define TITLE_SCREEN_PLAY_BUTTON_X_POS (GAME_WIDTH / 1.0f)
Basic_menu load_title_screen ();

void unload_title_screen ();

#endif
