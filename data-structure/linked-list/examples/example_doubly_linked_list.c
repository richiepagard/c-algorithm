#include <stdio.h>
#include <stdlib.h>

#include "../include/doubly_linked_list.h"


void run_doubly_linked_list_example() {
	NodeDoubly *head = NULL;

	printf("Running Doubly Linked List Example...\n");

    // initialize and insert nodes
	for(int i = 0; i <= 7; i++) init_node_doubly(&head, i);

    // display the list
    printf("Initial List: ");
	display_doubly(&head);
	printf("\n");

    // insert at beginning, at the end, and at a position
	insert_begin_doubly(&head, 23);
	insert_last_doubly(&head, 36);
	insert_position_doubly(&head, 2, 32);
	insert_after_node_doubly(head->next->next, 56);	// the value -56- going to insert at third position

    // list after insertion
    printf("List After Insertions: ");
	display_doubly(&head);
	printf("\n");


    // delete the first, the last, and by a value
	delete_first_doubly(&head);
	delete_last_doubly(&head);
	display_doubly(&head);
	delete_node_by_value(&head, 3);	// delete the node with value 3

    printf("List After Deletions: ");
    display_doubly(&head);
    printf("\n");


    /* you can call the tool functions here */


	// clean up the list
    delete_whole_list_doubly(&head);
    printf("List After Deleting All Nodes: ");
    display_doubly(&head);
    printf("\n");
}
