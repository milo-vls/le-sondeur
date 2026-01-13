#ifndef SPRITE_H
#define SPRITE_H

#include <raylib.h>

typedef struct Animation
{
        float image_height;
        float image_width;
        float first_image_x;
        float first_image_y;
        unsigned int image_count;
        unsigned int image_count_per_row;
        unsigned int fps;
} Animation;

typedef struct Sprite
{
        Texture2D texture;
        Animation animation;
        float accumulated_time;
        unsigned int current_image_index;
} Sprite;

void draw_sprite_image (Sprite *sprite, unsigned int image_index,
                        Vector2 position);
void draw_sprite (Sprite *sprite, Vector2 position);

void sprite_set_next_image_index (Sprite *sprite);

Sprite create_sprite (Texture2D texture, Animation animation);
Sprite create_sprite_auto_h_animation (Texture2D texture, unsigned int fps,
                                       unsigned int image_count);
#endif
