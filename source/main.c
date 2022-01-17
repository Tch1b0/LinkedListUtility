#include <stdlib.h>
#include <stdio.h>

#include <linkedlist.h>
#include <utility.h>

int main(int argc, char **argv)
{
    int arr_size = 10;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Create the linked list from an array
    Node *head = ll_create_from_array(arr_size, arr);

    printf("Default:\n");
    ll_print(head);

    printf("\nInsert node with value 11 at head:\n");
    ll_insert_at_head(&head, create_new_node(11));
    ll_print(head);

    printf("\nInsert node with value 12 at index 5:\n");
    ll_insert_at_index(&head, create_new_node(12), 5);
    ll_print(head);

    printf("\nSwap Nodes 1 and 4:\n");
    ll_swap_nodes(&head, 1, 4);
    ll_print(head);

    printf("\nLength of linked list:\n%d\n", ll_length(head));

    printf("\nLinked list as array:\n");
    print_array(ll_length(head), ll_to_array(head));

    ll_destroy(head);

    return 0;
}