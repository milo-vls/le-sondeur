#include "layer.h"
#include "linked_list.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void
add_layer (Linked_list *linked_list, Layer *layer)
{
        Linked_node *new_node = malloc (sizeof (Linked_node));
        new_node->data = layer;
        if (linked_list->size != sizeof (Layer))
        {
                printf ("Linked list of incorrect type, Layer expected");
                free (new_node);
                return;
        }
        // linked list empty
        if (linked_list->first_node == NULL)
        {
                linked_list->first_node = new_node;
                return;
        }
        Layer *first_element = linked_list->first_node->data;
        // layer must be the new first element of the list
        if (first_element->depth <= layer->depth)
        {
                new_node->next_node = linked_list->first_node;
                linked_list->first_node = new_node;
                return;
        }

        // there is one unique node
        if (linked_list->first_node->next_node == NULL)
        {
                linked_list->first_node->next_node = new_node;
                return;
        }
        Linked_node *selected_node = linked_list->first_node->next_node;
        Linked_node *previous_node = linked_list->first_node;
        while (selected_node != NULL)
        {
                Layer *selected_layer = selected_node->data;
                if (selected_layer->depth <= layer->depth)
                {
                        insert_node_after (previous_node, new_node);
                        return;
                }
                previous_node = selected_node;
                selected_node = selected_node->next_node;
        }
        // end of list reached
        previous_node->next_node = new_node;
}

void
draw_layers (Linked_list *layers)
{
        Linked_node *selected_node = layers->first_node;

        while (selected_node != NULL)
        {
                Layer *selected_layer = (Layer *)selected_node->data;

                DrawTexture (selected_layer->render_texture_2d.texture, 0, 0,
                             WHITE);
                selected_node = selected_node->next_node;
        }
}

void
clear_layers (Linked_list *layers)
{
        Linked_node *selected_node = layers->first_node;
        while (selected_node != NULL)
        {
                Layer *selected_layer = (Layer *)selected_node->data;
                BeginTextureMode(selected_layer->render_texture_2d);
                ClearBackground(BLANK);
                EndTextureMode();
                selected_node = selected_node->next_node;
        }
}
