#include <stdio.h>
#include <stdlib.h>

#include "../include/circular_singly_linked_list.h"


void run_circular_singly_linked_list_example() {
	NodeCircularSingly *head = NULL;

	printf("Running Circular Singly Linked List Example...\n\n");

    // initialize and insert nodes
	insertBeginCircularSingly(&head, 6);
	insertBeginCircularSingly(&head, 3);
	insertLastCircularSingly(&head, 9);

    // display the list after insertions
    printf("List After Insertions: \n");
	displayCircularSingly(&head);
	printf("\n");

    // delete the first and the last node
	deleteFirstCircularSingly(&head);
	deleteLastCircularSingly(&head);

    printf("List After Deletions: ");
	displayCircularSingly(&head);
	printf("\n");


	/* you can call the tool functions here */



    // clean up the list
	deleteWholeListCircularSingly(&head);
	printf("List After Deleting All Nodes: ");
    displayCircularSingly(&head);
    printf("\n");
}
