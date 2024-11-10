#include <stdio.h>
#include <stdlib.h>

#include "../include/singly_linked_list.h"


void run_singly_linked_list_example() {
    Node *head = NULL;
    Node *new_node;

    int data_search, index_data_find;

    printf("Running Singly Linked List Example...\n");

    // initialize and insert nodes
    new_node = initialNodeSingly(10);
    insertLastSingly(&head, new_node);

    for(int i = 0; i <= 7; i++)
    {
        new_node = initialNodeSingly(i);
        // insertLast(&head, new_node);
        insertBeginSingly(&head, new_node);
    }

    // display the list
    printf("Initial List: ");
    displaySingly(&head);
    printf("\n");

    // insert at beginning and at a position
    new_node = initialNodeSingly(0);
    insertBeginSingly(&head, new_node);
    new_node = initialNodeSingly(100);
    insertPositionSingly(&head, new_node, 3);

    printf("List After Insertions: \n");
    displaySingly(&head);
    printf("\n");

    // delete a node by position
    deletePositionSingly(&head, 2);
    printf("List After Deletion at Position 2: \n");
    displaySingly(&head);
    printf("\n");


    /* you can call the tool functions here */



	// clean up the list
    deleteWholeListSingly(&head);
    printf("List After Deleting All Nodes:");
    displaySingly(&head);
    printf("\n");
}
