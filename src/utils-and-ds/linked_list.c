#include "linked_list.h"

void
insert_node_after (Linked_node *node, Linked_node *node_to_insert)
{
        if (node == NULL || node_to_insert == NULL)
                return;
        node_to_insert->next_node = node->next_node;
        node->next_node = node_to_insert;
}
