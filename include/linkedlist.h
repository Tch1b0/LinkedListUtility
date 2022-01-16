#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
    int value;
    struct node *next;
};

typedef struct node Node;

void ll_print(Node *head);
Node *create_new_node(int value);
Node *ll_insert_at_head(Node **head, Node *node_to_insert);
Node *ll_insert_at_index(Node **head, Node *node_to_insert, unsigned int index);
Node *ll_swap_nodes(Node **head, unsigned int first_index, unsigned int second_index);
Node *ll_create_from_array(int array_length, int *array);
int ll_length(Node *head);
Node *ll_get_index(Node *head, int index);
int *ll_to_array(Node *head);

#endif