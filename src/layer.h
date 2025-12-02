#ifndef LAYER_H
#define LAYER_H
#include "linked_list.h"
#include <raylib.h>

typedef struct Layer
{
        unsigned int depth;
        RenderTexture2D render_texture_2d;
} Layer;

void add_layer (Linked_list *linked_list, Layer *layer);

#endif /*LAYER_H*/
