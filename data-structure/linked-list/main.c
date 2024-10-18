#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


int main() {
    Node *head = NULL;  // start node of the linked list
    Node *new_node;

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
    printf("\nThe Maximum Data: %d\n", findMaximumSingly(&head));
	printf("Quantity Of Nodes: %d\n", countNodeSingly(&head));

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
