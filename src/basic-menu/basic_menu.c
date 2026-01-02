#include "basic-menu/basic_menu.h"
#include "dimensions.h"
#include <raylib.h>

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

Basic_menu
create_basic_menu (int width, int height)
{
        Basic_menu to_return = (Basic_menu){};
        to_return.menu_render = LoadRenderTexture (width, height);
        to_return.button_state
            = (Button_state){ BASIC_MENU_NO_BUTTON_HOVERED,
                              BASIC_MENU_NO_BUTTON_HOVERED,
                              BASIC_MENU_NO_BUTTON_HOVERED };
        for (int i_depth = 0; i_depth < NB_BASIC_MENU_DEPTHS; i_depth++)
        {
                to_return.nb_buttons[i_depth] = 0;
                to_return.render_textures[i_depth]
                    = LoadRenderTexture (width, height);
        }
        return to_return;
}

void
unload_basic_menu (Basic_menu *basic_menu)
{
        UnloadRenderTexture (basic_menu->menu_render);
        for (int i = 0; i < NB_BASIC_MENU_DEPTHS; i++)
                UnloadRenderTexture (basic_menu->render_textures[i]);
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

Button_index
basic_menu_hovered_button_index (Basic_menu *basic_menu)
{
        Vector2 mouse_pos = GetMousePosition();
        unsigned int nb_buttons;
        for (int i_depth = NB_BASIC_MENU_DEPTHS - 1; i_depth >= 0; i_depth --)
        {
                nb_buttons = basic_menu->nb_buttons[i_depth];
                for (unsigned int i_button = 0; i_button < nb_buttons; 
                        i_button ++)
                        if (point_in_button(&basic_menu->buttons[i_depth][i_button], mouse_pos))
                                return (Button_index) {.depth = i_depth, .index = i_button};
        }
        return (Button_index) {.depth = -1, .index = -1};
}

void
draw_buttons_and_update_button_state (Basic_menu *basic_menu)
{
        // optimisations possibles
        Button_index hovered_button_index = basic_menu_hovered_button_index (basic_menu);
        for (int i_depth = 0; i_depth < NB_BASIC_MENU_DEPTHS; i_depth++)
        {
                BeginTextureMode (basic_menu->render_textures[i_depth]);
                Button *buttons = basic_menu->buttons[i_depth];
                for ( int i_button = 0;
                        i_button < (int) basic_menu->nb_buttons[i_depth]; i_button++)
                {
                        if (i_depth == (int) hovered_button_index.depth 
                                && i_button ==  hovered_button_index.index)
                                draw_sprite (&buttons[i_button].sprite_hovered, 
                                             buttons[i_button].position);
                        else
                                draw_sprite (&buttons[i_button].sprite,
                                             buttons[i_button].position);
                }
                EndTextureMode ();
        }
}

void
clear_basic_menu_renderers (Basic_menu *basic_menu)
{
        BeginTextureMode (basic_menu->menu_render);
        ClearBackground (BLANK);
        EndTextureMode ();
        for (int i_depth = 0; i_depth < NB_BASIC_MENU_DEPTHS; i_depth++)
        {
                BeginTextureMode (basic_menu->render_textures[i_depth]);
                ClearBackground (BLANK);
                EndTextureMode ();
        }
}
void
update_basic_menu_texture (Basic_menu *basic_menu)
{
        BeginTextureMode (basic_menu->menu_render);
        for (int i_depth = NB_BASIC_MENU_DEPTHS - 1; i_depth-- > 0;)
                DrawTexture (basic_menu->render_textures[i_depth].texture, 0,
                             0, WHITE);
        EndTextureMode ();
}
void
draw_menu_on_screen (Basic_menu *basic_menu)
{
        Rectangle source = (Rectangle){ .x = 0,
                                        .y = 0,
                                        .height = (float)GAME_HEIGHT,
                                        .width = (float)GAME_WIDTH };
        Rectangle dest = (Rectangle){ .x = 0,
                                      .y = 0,
                                      .width = (float)GAME_WIDTH,
                                      .height = (float)-GAME_HEIGHT };
        DrawTexturePro (basic_menu->menu_render.texture, source, dest,
                        (Vector2){ 0., 0. }, 0.0f, WHITE);
}
void
update_basic_menu (Basic_menu *basic_menu)
{
        clear_basic_menu_renderers (basic_menu);
        draw_buttons_and_update_button_state (basic_menu);
        update_basic_menu_texture (basic_menu);
        draw_menu_on_screen (basic_menu);
}
