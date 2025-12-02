#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct Linked_node Linked_node;

typedef struct Linked_node
{
        void *data;
        Linked_node *next_node;
} Linked_node;

typedef struct Linked_list
{
        size_t size;
        Linked_node *first_node;
} Linked_list;

void insert_node_after (Linked_node *, Linked_node *);

#endif /*LINKED_LIST_H*/
