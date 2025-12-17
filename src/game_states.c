#include "game_states.h"
#include "asset/sprite.h"
#include <raylib.h>

void
draw_game (World *world)
{
        BeginDrawing ();
        ClearBackground (WHITE);
        EndDrawing ();
}

void
update (World *world)
{
        switch (world->game_state)
        {
        case GAME_STATE_BASIC_MENU:
                update_basic_menu (&world->basic_menu);
                break;
        }
        draw_game (world);
}

//---BASIC MENU ---//

void
draw_depth_buttons (Button *buttons, unsigned int nb_buttons,
                    RenderTexture2D render_texture, Button_state *button_state)
{
        BeginTextureMode (render_texture);
        for (int i_button = 0; i_button < nb_buttons; i_button++)
                draw_sprite (&buttons[i_button].sprite,
                             buttons[i_button].position);

        EndTextureMode ();
}

Button_state
draw_button_and_update_button_state (Basic_menu *basic_menu)
{
        bool click_released = IsMouseButtonReleased (MOUSE_BUTTON_LEFT);
        bool click_held = IsMouseButtonDown (MOUSE_BUTTON_LEFT);
        bool click_pressed = IsMouseButtonPressed (MOUSE_BUTTON_LEFT);

        Button_state new_button_state = (Button_state){ -1, -1, -1 };
        for (int i_depth = 0; i_depth < NB_BASIC_MENU_DEPTHS; i_depth++)
                draw_depth_buttons (basic_menu->buttons[i_depth],
                                    basic_menu->nb_buttons[i_depth],
                                    basic_menu->render_textures[i_depth],
                                    &new_button_state);
        return new_button_state;
}
