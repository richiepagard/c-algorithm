#include <stdio.h>
#include <stdlib.h>

#include "include/doubly_linked_list.h"


NodeDoubly *initialNodeDoubly(NodeDoubly **head, int value) {
	/*	initialize a new node, if the list is empty, then the `head` will update to the new node,
		but if the list isn't empty, the new node will set to the last node. */

	NodeDoubly *new_node = (NodeDoubly*) malloc(sizeof(NodeDoubly));	// initialize a new node

	new_node->data = value;
	new_node->next = NULL;

	if(*head == NULL)
	{
		/*	if the `head` node is NULL(the list is empty), the `previous` of the new node
			will set to the NULL and the `head` will update to the new node. */
		insertBeginDoubly(&(*head), value);
	} else {
		/* if the list isn't empty, the new node will set to the last node  */
		insertLastDoubly(&(*head), value);
	}
}


void insertBeginDoubly(NodeDoubly **head, int value) {
	/*	insert at the beginning of the list
		first node is the node that the `previous` points to the NULL */

	NodeDoubly *new_node = (NodeDoubly*) malloc(sizeof(NodeDoubly));

	new_node->data = value;
	new_node->next = (*head);	// the new node's `next` is points to the current `head` node
	new_node->previous = NULL;

	if( (*head) != NULL ) (*head)->previous = new_node;	// the current `head` node's previous is points to the new node
	(*head) = new_node;	// the new node is set to the `head` node
}

void insertLastDoubly(NodeDoubly **head, int value) {
	/*	insert at the last of the list
		last node is the node that the `next` points to the NULL */

	NodeDoubly *new_node = (NodeDoubly*) malloc(sizeof(NodeDoubly));
	NodeDoubly *current = (*head);

	new_node->data = value;
	new_node->next = NULL;

	while(current->next != NULL) current = current->next;	// traverse the nodes until the node current last node
	current->next = new_node;	// the current last node's next is points to the new node
	new_node->previous = current;	// the new node's previous is points to the current
}


void deleteWholeListDoubly(NodeDoubly **head) {
	/*	function for delete the whole list and free the memory.
	 	use the recursive way.*/

	if(*head == NULL) return;

	deleteWholeListDoubly(&(*head)->next);
	free(*head);
}


void displayDoubly(NodeDoubly **head) {
    if(*head == NULL)
    {
        printf("\nThe List Is Empty !\n");
        return;
    }

    NodeDoubly *temp = *head;
    printf("The Elements Of The List: \n\t");
    printf("NULL");
	while(temp != NULL)
	{
		printf(" <-> %d", temp->data);
        if(temp->next == NULL) printf(" <-> ");
		temp = temp->next;
	}
	printf("NULL\n");
}
