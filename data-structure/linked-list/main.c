#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "include/singly_linked_list.h"
#include "include/doubly_linked_list.h"


int main() {
    Node *head = NULL;  // start node of the linked list
    Node *new_node;

	// Singly Linked List
    new_node = initialNodeSingly(10);
    insertLastSingly(&head, new_node);

    for(int i = 0; i <= 7; i++)
    {
        new_node = initialNodeSingly(i);
        // insertLast(&head, new_node);
        insertBeginSingly(&head, new_node);
    }

    new_node = initialNodeSingly(45);
    insertBeginSingly(&head, new_node);

    new_node = initialNodeSingly(46);
	insertPositionSingly(&head, new_node, 3);	// insert at position

    displaySingly(&head);   // show the list before deletion action
	printf("\n");

    deletePositionSingly(&head, 2); // delete at position
    displaySingly(&head);   // show the list after deletion action

	printf("\n	Display List, Reversed: \n\t");
    displayReverseSingly(&head);    // show the list reverse
    printf("NULL\n");

	// call the tool functions
	int data_search, index_data_find;

    printf("\nThe Maximum Data: %d\n", findMaximumSingly(&head));
	printf("Quantity Of Nodes: %d\n", countNodeSingly(&head));

	printf("\nEnter a number to search in the list: ");
	scanf("%d", &data_search);
	searchRecursiveSingly(&head, data_search) ? printf("%d Found In The List :)\n", data_search) : printf("%d Not Found In The List :(\n", data_search);

	printf("\nEnter an index to find the data of the index in the list: ");
	scanf("%d", &index_data_find);
	printf("Index %d Has The Number %d.\n", index_data_find, findIndexRecursiveSingly(&head, index_data_find));

	// concatenate two singly linked list
	Node *head2 = NULL;
	Node *new_node2;
	new_node2 = initialNodeSingly(90);
	insertBeginSingly(&head2, new_node2);

	Node *result = concatenateTwoListSingly(&head, &head2);
	printf("\nThe Result Of Concatenation: \n\t");
	displaySingly(&result);


	// delete the whole list and free the memory, use the recursive function for this
	deleteWholeListSingly(&head);
	printf("\nThe Whole List Deleted !\n");
	// End Singly Linked List

	// Doubly Linked List
	NodeDoubly *head_doubly = NULL;
	NodeDoubly *new_node_doubly;
	
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


	// delete the whole list and free the memory, use the recursive function for this
	deleteWholeListDoubly(&head_doubly);
	printf("\nThe Whole List Deleted !\n");
	// End Doubly Linked List

	/* if you want to delete all the nodes and free the memory, 
	 * use these lines and remove the `deleteWholeListSingly method or comment it

		// Free the memory used for the nodes
		while (head != NULL) {
			Node *tmp = head;
			head = head->next;
			free(tmp);
		}

	*/

    return 0;
}