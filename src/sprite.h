#ifndef SPRITE_H
#define SPRITE_H

#include <raylib.h>

typedef struct Animation
{
        unsigned int length;
        unsigned int width;
        unsigned int image_count;
        unsigned int origin_x;
        unsigned int origin_y;

} Animation;

typedef struct Sprite
{
        Texture texture;
        Animation animation;
} Sprite;

#endif
