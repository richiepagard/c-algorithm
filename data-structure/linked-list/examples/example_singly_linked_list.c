#include <stdio.h>
#include <stdlib.h>

#include "../include/singly_linked_list.h"


void run_singly_linked_list_example() {
    Node *head = NULL;
    Node *new_node;

    int data_search, index_data_find;

    printf("Running Singly Linked List Example...\n");

    // initialize and insert nodes
    new_node = initial_node_singly(10);
    insert_last_singly(&head, new_node);

    for(int i = 0; i <= 7; i++)
    {
        new_node = initial_node_singly(i);
        // insertLast(&head, new_node);
        insert_begin_singly(&head, new_node);
    }

    // display the list
    printf("Initial List: ");
    display_singly(&head);
    printf("\n");

    // insert at beginning and at a position
    new_node = initial_node_singly(0);
    insert_begin_singly(&head, new_node);
    new_node = initial_node_singly(100);
    insert_position_singly(&head, new_node, 3);

    printf("List After Insertions: \n");
    display_singly(&head);
    printf("\n");

    // delete a node by position
    delete_position_singly(&head, 2);
    printf("List After Deletion at Position 2: \n");
    display_singly(&head);
    printf("\n");


    /* you can call the tool functions here */



	// clean up the list
    delete_whole_list_singly(&head);
    printf("List After Deleting All Nodes:");
    display_singly(&head);
    printf("\n");
}
