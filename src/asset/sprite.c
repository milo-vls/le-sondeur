#include "sprite.h"
#include <raylib.h>
#include <stdlib.h>

void
draw_sprite_image (Sprite *sprite, unsigned int image_index, Vector2 position)
{
        float image_width = sprite->animation.image_width;
        float image_height = sprite->animation.image_height;
        div_t image_row_col
            = div (image_index, sprite->animation.image_count_per_row);
        float source_x = image_row_col.rem * image_width;
        float source_y = image_row_col.quot * image_height;
        Rectangle source = { .height = sprite->animation.image_height,
                             .width = image_width,
                             .x = source_x,
                             .y = source_y };
        Rectangle destination = source;
        destination.x = position.x;
        destination.y = position.y;

        DrawTexturePro (sprite->texture, source, destination,
                        (Vector2){ 0, 0 }, 0, WHITE);
}

void
draw_sprite (Sprite *sprite, Vector2 position)
{
        draw_sprite_image (sprite, sprite->current_image_index, position);
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
