#include "layer.h"
#include "linked_list.h"
#include "sprite.h"
#include <raylib.h>
#include <stdlib.h>

#define GAME_WIDTH 800
#define GAME_HEIGHT 800

typedef enum GAME_STATE
{
        GAME_STATE_TITLE_SCREEN,
} GAME_STATE;

typedef struct World
{
        GAME_STATE game_state;
        Linked_list layers;
} World;

void
update (World *world)
{
        BeginDrawing ();
        ClearBackground (PURPLE);

        EndDrawing ();
}

int
main (void)
{
        InitWindow (GAME_WIDTH, GAME_HEIGHT, "Le sondeur.");
        SetTargetFPS (60);
        Linked_list layers = { sizeof (Layer), NULL };
        Layer *gui_layer_ptr = (Layer *)(malloc (sizeof (Layer)));
        *gui_layer_ptr
            = (Layer){ 0, LoadRenderTexture (GAME_WIDTH, GAME_HEIGHT) };
        add_layer (&layers, gui_layer_ptr);
        World world
            = { .game_state = GAME_STATE_TITLE_SCREEN, .layers = layers };
        Sprite sprite = (Sprite){
                LoadTexture ("../ressources/buttons/jouer/jouer_ss.png"),
                (Animation){}, 3, 0, 0
        };
        sprite.animation
            = (Animation){ sprite.texture.height, 309, 0, 0, 3, 3, 3 };

        while (!WindowShouldClose ())
        {

                BeginTextureMode (gui_layer_ptr->render_texture_2d);
                draw_sprite (&sprite,
                             (Vector2){ (float)GetRenderHeight () / 2,
                                        (float)GetRenderWidth () / 2 });
                EndTextureMode ();
                update (&world);
        }
        CloseWindow ();
        return 1;
}
