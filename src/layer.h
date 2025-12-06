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
void draw_layers (Linked_list *layers);
void clear_layers (Linked_list *layers);
#endif /*LAYER_H*/
