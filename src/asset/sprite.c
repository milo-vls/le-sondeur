#include "sprite.h"
#include <raylib.h>
#include <stdlib.h>

void
draw_sprite_image (Sprite *sprite, unsigned int image_index, Vector2 position)
{
        Animation anim = sprite->animation;
        float image_width = anim.image_width;
        float image_height = anim.image_height;
        div_t image_row_col = div (image_index, anim.image_count_per_row);
        float source_x = anim.first_image_x + image_row_col.rem * image_width;
        float source_y
            = anim.first_image_y + image_row_col.quot * image_height;
        Rectangle source = { .height = anim.image_height,
                             .width = image_width,
                             .x = source_x,
                             .y = source_y };
        Rectangle destination = { .height = source.height,
                                  .width = source.width,
                                  .x = position.x,
                                  .y = position.y };
        DrawTexturePro (sprite->texture, source, destination,
                        (Vector2){ 0, 0 }, 0, WHITE);
}

void
draw_sprite (Sprite *sprite, Vector2 position)
{
        draw_sprite_image (sprite, sprite->current_image_index, position);
}

Animation
create_animation (float first_image_x, float first_image_y,
                  unsigned int image_count, unsigned int img_count_per_row,
                  float height, float width, unsigned int fps)
{

        return (Animation){ .first_image_x = first_image_x,
                            .first_image_y = first_image_y,
                            .image_count = image_count,
                            .image_count_per_row = img_count_per_row,
                            .image_height = height,
                            .image_width = width,
                            .fps = fps };
}

Sprite
create_sprite (Texture2D texture, Animation animation, unsigned int fps)
{
        return (Sprite){ .animation = animation,
                         .texture = texture,
                         .fps = fps,
                         .accumulated_time = 0.0f,
                         .current_image_index = 0 };
}

Sprite
create_sprite_auto_h_animation (Texture2D texture, unsigned int fps,
                                unsigned int image_count)
{
        Animation anim
            = (Animation){ .image_height = texture.height,
                           .image_width = texture.width / (float)image_count,
                           .first_image_x = 0,
                           .first_image_y = 0,
                           .image_count = image_count,
                           .image_count_per_row = image_count,
                           .fps = fps };
        return create_sprite (texture, anim, fps);
}
