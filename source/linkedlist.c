#include <stdlib.h>
#include <stdio.h>

#include <linkedlist.h>

/*
 * Create a new linked list
 */
void ll_print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*
 * Create a new node
 */
Node *create_new_node(int value)
{
    Node *result = malloc(sizeof(Node));
    result->value = value;
    result->next = NULL;
    return result;
}

/*
 * Insert a node at the head
 */
Node *ll_insert_at_head(Node **head, Node *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

/*
 * Insert a node at a certain index
 */
Node *ll_insert_at_index(Node **head, Node *node_to_insert, unsigned int index)
{
    // Insert node at head if index is 0
    if (index == 0)
    {
        ll_insert_at_head(head, node_to_insert);
    }
    else
    {
        // Index is not 0, so get the node with the previous index
        Node *prev_node = ll_get_index(*head, index - 1);

        // If the previous node is the last one in the chain...
        if (prev_node->next == NULL)
        {
            prev_node->next = node_to_insert;
            node_to_insert->next = NULL;
        }
        else
        {
            // There is a node after the chosen index
            Node *next_node = prev_node->next;

            // Set the next node of the node to insert to the node that was
            // at this index previously
            node_to_insert->next = next_node;

            // set the next node of the previous node to the node to insert
            prev_node->next = node_to_insert;
        }
    }

    return *head;
}

Node *ll_swap_nodes(Node **head, unsigned int first_index, unsigned int second_index)
{
    Node *first_node = ll_get_index(*head, first_index);
    Node *second_node = ll_get_index(*head, second_index);
    Node *tmp;

    if (first_index == 0 || second_index == 0)
    {
        tmp = (*head)->next;
        if (first_index == 0)
        {
            first_node->next = second_node->next;
            second_node->next = tmp;

            ll_get_index(*head, second_index - 1)->next = first_node;
            *head = second_node;
        }
        else
        {
            first_node->next = tmp;
            second_node->next = first_node->next;

            ll_get_index(*head, first_index - 1)->next = second_node;
            *head = first_node;
        }
    }
    else
    {
        ll_get_index(*head, first_index - 1)->next = second_node;
        tmp = second_node->next;
        second_node->next = first_node->next;

        ll_get_index(*head, second_index - 1)->next = first_node;
        first_node->next = tmp;
    }

    return *head;
}

/*
 * Create a new linked list from an array
 */
Node *ll_create_from_array(int array_length, int *array)
{
    Node *head = NULL;
    Node *new_node;

    for (int i = 0; i < array_length; i++)
    {
        new_node = create_new_node(array[i]);
        ll_insert_at_head(&head, new_node);
    }

    return head;
}

/*
 * Get the length of a linked list
 */
int ll_length(Node *head)
{
    int i = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    return i;
}

/*
 * Get a certain node by its index in the linked list
 */
Node *ll_get_index(Node *head, int index)
{
    Node *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        if (i == index)
        {
            return temp;
        }

        temp = temp->next;
        i++;
    }

    // Index out of range
    return NULL;
}

/*
 * Creates an array from a linked list
 */
int *ll_to_array(Node *head)
{
    int length = ll_length(head);
    int *array = malloc(sizeof(int) * length);
    Node *temp = head;

    for (int i = length - 1; i > -1; i--)
    {
        if (temp == NULL)
            break;
        array[i] = temp->value;
        temp = temp->next;
    }

    return array;
}