#include <stdio.h>
#include <stdlib.h>

#include "../include/circular_doubly_linked_list.h"

void run_circular_doubly_linked_list_example() {
	NodeCircularDoubly *head = NULL;
	NodeCircularDoubly *last = NULL;

	printf("Running Circular Doubly Linked List Example...\n");

    // initialize and insert nodes
	insertBeginCircularDoubly(&head, &last, 6);
	insertBeginCircularDoubly(&head, &last, 3);
	insertLastCircularDoubly(&head, &last, 9);

    // display the list after insertions
    printf("List After Insertions: \n");
	displayCircularDoubly(&head, &last);
    printf("\n");

    // delete the first and the last node
    deleteFirstCircularDoubly(&head, &last);
    deleteLastCircularDoubly(&head, &last);

    // display the list after insertions
    printf("List After Deletion: \n");
	displayCircularDoubly(&head, &last);
    printf("\n");

    /* you can call the tool functions here */



    // clean up the list
	deleteWholeListCircularDoubly(&head, &last);
    printf("List After Deleting All Nodes: \n");
    displayCircularDoubly(&head, &last);
    printf("\n");
}
