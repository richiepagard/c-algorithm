#include <stdio.h>
#include <stdlib.h>

#include "../include/circular_singly_linked_list.h"


void run_circular_singly_linked_list_example() {
	NodeCircularSingly *head = NULL;

	printf("Running Circular Singly Linked List Example...\n\n");

    // initialize and insert nodes
	insert_begin_circular_singly(&head, 6);
	insert_begin_circular_singly(&head, 3);
	insert_last_circular_singly(&head, 9);

    // display the list after insertions
    printf("List After Insertions: \n");
	display_circular_singly(&head);
	printf("\n");

    // delete the first and the last node
	delete_first_circular_singly(&head);
	delete_last_circular_singly(&head);

    printf("List After Deletions: ");
	display_circular_singly(&head);
	printf("\n");


	/* you can call the tool functions here */



    // clean up the list
	delete_whole_list_circular_singly(&head);
	printf("List After Deleting All Nodes: ");
    display_circular_singly(&head);
    printf("\n");
}
