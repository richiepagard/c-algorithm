#include <stdio.h>
#include <stdlib.h>

#include "../include/circular_doubly_linked_list.h"

void run_circular_doubly_linked_list_example() {
	NodeCircularDoubly *head = NULL;
	NodeCircularDoubly *last = NULL;

	printf("Running Circular Doubly Linked List Example...\n");

    // initialize and insert nodes
	insert_begin_circular_doubly(&head, &last, 6);
	insert_begin_circular_doubly(&head, &last, 3);
	insert_last_circular_doubly(&head, &last, 9);

    // display the list after insertions
    printf("List After Insertions: \n");
	display_circular_doubly(&head, &last);
    printf("\n");

    // delete the first and the last node
    delete_first_circular_doubly(&head, &last);
    delete_last_circular_doubly(&head, &last);

    // display the list after insertions
    printf("List After Deletion: \n");
	display_circular_doubly(&head, &last);
    printf("\n");

    /* you can call the tool functions here */



    // clean up the list
	delete_whole_list_circular_doubly(&head, &last);
    printf("List After Deleting All Nodes: \n");
    display_circular_doubly(&head, &last);
    printf("\n");
}
