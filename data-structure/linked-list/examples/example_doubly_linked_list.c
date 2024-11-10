#include <stdio.h>
#include <stdlib.h>

#include "../include/doubly_linked_list.h"


void run_doubly_linked_list_example() {
	NodeDoubly *head = NULL;
	
	printf("Running Doubly Linked List Example...\n");

    // initialize and insert nodes
	for(int i = 0; i <= 7; i++) initialNodeDoubly(&head, i);

    // display the list
    printf("Initial List: ");
	displayDoubly(&head);
	printf("\n");

    // insert at beginning, at the end, and at a position
	insertBeginDoubly(&head, 23);
	insertLastDoubly(&head, 36);
	insertPositionDoubly(&head, 2, 32);
	insertAfterNodeDoubly(head->next->next, 56);	// the value -56- going to insert at third position

    // list after insertion
    printf("List After Insertions: ");
	displayDoubly(&head);
	printf("\n");


    // delete the first, the last, and by a value
	deleteFirstDoubly(&head);
	deleteLastDoubly(&head);
	displayDoubly(&head);
	deleteNodeByValue(&head, 3);	// delete the node with value 3

    printf("List After Deletions: ");
    displayDoubly(&head);
    printf("\n");


    /* you can call the tool functions here */


	// clean up the list
    deleteWholeListDoubly(&head);
    printf("List After Deleting All Nodes: ");
    displayDoubly(&head);
    printf("\n");
}
