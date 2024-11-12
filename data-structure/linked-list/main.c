#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "include/singly_linked_list.h"
#include "include/doubly_linked_list.h"

#include "include/circular_singly_linked_list.h"
#include "include/circular_doubly_linked_list.h"


int main() {
	printf("Running Linked List Examples... \n\n");
	
<<<<<<< HEAD
	printf("\n\n\t\t\tStart The Doubly Linked List\n\n");

	for(int i = 0; i <= 7; i++) initialNodeDoubly(&head_doubly, i);
	displayDoubly(&head_doubly);
	printf("\n");

	insertBeginDoubly(&head_doubly, 23);
	displayDoubly(&head_doubly);
	printf("\n");

	initialNodeDoubly(&head_doubly, 13);
	displayDoubly(&head_doubly);
	printf("\n");

	insertLastDoubly(&head_doubly, 36);
	displayDoubly(&head_doubly);
	printf("\n");

	insertPositionDoubly(&head_doubly, 2, 32);	// insert `32` to the second index, indexes start from `0`
	displayDoubly(&head_doubly);
	printf("\n");

	insertAfterNodeDoubly(head_doubly->next->next, 56);	// the value -56- going to insert at third position
	displayDoubly(&head_doubly);
	printf("\n");

	deleteFirstDoubly(&head_doubly);
	displayDoubly(&head_doubly);
	printf("\n");

	deleteLastDoubly(&head_doubly);
	displayDoubly(&head_doubly);
	printf("\n");

	deleteNodeByValue(&head_doubly, 3);	// delete the node with value 3
	displayDoubly(&head_doubly);
	printf("\n");

	printf("\nThe Doubly Linked List After Reversing Action: \n");
	reverseListDoubly(&head_doubly);
	displayDoubly(&head_doubly);
	printf("\n");

	// delete the whole list and free the memory, use the recursive function for this
	deleteWholeListDoubly(&head_doubly);
	printf("\nThe Whole List Deleted !\n");
	// End Doubly Linked List

	// Circular Singly Linked List
	NodeCircularSingly *head_circular_singly;
	NodeCircularSingly *new_node_curcular_singly;

	printf("\n\n\t\t\tStart The Circular Singly Linked List\n\n");

	insertBeginCircularSingly(&head_circular_singly, 3);
	insertBeginCircularSingly(&head_circular_singly, 6);
	insertBeginCircularSingly(&head_circular_singly, 9);
	displayCircularSingly(&head_circular_singly);
	printf("\n");

	insertLastCircularSingly(&head_circular_singly, 12);
	displayCircularSingly(&head_circular_singly);
	printf("\n");

	printf("The quantity of the nodes in the list is %d\n", countNodesCircularSingly(&head_circular_singly));
	printf("\n");

	deleteFirstCircularSingly(&head_circular_singly);
	displayCircularSingly(&head_circular_singly);
	printf("\n");

	deleteLastCircularSingly(&head_circular_singly);
	displayCircularSingly(&head_circular_singly);
	printf("\n");


	deleteWholeListCircularSingly(&head_circular_singly);
	// End Circular Singly Linked List

	// Circular Doubly Linked List
	NodeCircularDoubly *head_circular_doubly = NULL;
	NodeCircularDoubly *last_circular_doubly = NULL;

	printf("\n\n\t\t\tStart The Circular Doubly Linked List\n\n");

	insertBeginCircularDoubly(&head_circular_doubly, &last_circular_doubly, 3);
	insertBeginCircularDoubly(&head_circular_doubly, &last_circular_doubly, 6);
	insertBeginCircularDoubly(&head_circular_doubly, &last_circular_doubly, 9);
	displayCircularDoubly(&head_circular_doubly, &last_circular_doubly);

	insertLastCircularDoubly(&head_circular_doubly, &last_circular_doubly, 12);
	displayCircularDoubly(&head_circular_doubly, &last_circular_doubly);

	deleteWholeListCircularDoubly(&head_circular_doubly);
	// End Circular Doubly Linked List

	/* if you want to delete all the nodes and free the memory, 
	 * use these lines and remove the `deleteWholeListSingly method or comment it

		// Free the memory used for the nodes
		while (head != NULL) {
			Node *tmp = head;
			head = head->next;
			free(tmp);
		}
=======
	run_circular_doubly_linked_list_example();
>>>>>>> main

	/*	similarly, can call other example functions for other linked lists here
		e.g.,	run_singly_linked_list_example();
	*/


    return 0;
}
