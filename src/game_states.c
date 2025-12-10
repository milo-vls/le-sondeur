#include "game_states.h"
#include "dimensions.h"
#include "layer.h"
#include "sprite.h"
#include <raylib.h>
#include <stdlib.h>

void
draw_game (World *world)
{
        BeginDrawing ();
        ClearBackground (WHITE);
        draw_layers (&world->layers);
        EndDrawing ();
}

void
update (World *world)
{
        clear_layers (&world->layers);
        switch (world->game_state)
        {
        case GAME_STATE_TITLE_SCREEN:
                update_basic_menu (world->basic_menu);
                break;
        }
        draw_game (world);
}

//---BASIC MENU ---//

bool
point_in_button (Button *button, Vector2 point_position)
{
        Rectangle rectangle
            = (Rectangle){ .x = button->position.x,
                           .y = button->position.y,
                           .width = button->sprite.animation.image_width,
                           .height = button->sprite.animation.image_height };
        return CheckCollisionPointRec (point_position, rectangle);
}
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

Basic_menu *
create_basic_menu ()
{
        Basic_menu *to_return = malloc (sizeof (Basic_menu));
        to_return->button_state = (Button_state){ -1, -1, -1 };
        for (int i_depth = 0; i_depth < NB_BASIC_MENU_DEPTHS; i_depth++)
        {
                to_return->render_textures[i_depth]
                    = LoadRenderTexture (GAME_WIDTH, GAME_HEIGHT);
                to_return->nb_buttons[i_depth] = 0;
        }
        to_return->menu_render = LoadRenderTexture (GAME_WIDTH, GAME_HEIGHT);
        return to_return;
}

void
basic_menu_add_button (BASIC_MENU_DEPTHS depth, Button button,
                       Button_method button_method, Basic_menu *basic_menu)
{
        unsigned int button_index = basic_menu->nb_buttons[depth];
        basic_menu->nb_buttons[depth]++;
        basic_menu->button_method[depth][button_index] = button_method;
        basic_menu->buttons[depth][button_index] = button;
}

void
update_basic_menu (Basic_menu *basic_menu)
{
        basic_menu->button_state
            = draw_button_and_update_button_state (basic_menu);
        BeginTextureMode (basic_menu->menu_render);
        for (int i_depth = NB_BASIC_MENU_DEPTHS - 1; i_depth != 0; i_depth--)
                DrawTexture (basic_menu->render_textures[i_depth].texture,
                             GAME_WIDTH / 2, GAME_WIDTH / 2, WHITE);
        EndTextureMode ();
}
