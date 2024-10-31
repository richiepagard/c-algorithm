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

void insertPositionDoubly(NodeDoubly **head, int position, int value) {
	/*	insert a new node at the position, if the position is invalid then exit the program,
		but if the position is the last position then insert a new node at the end of the list,
		and if the position is at first or between first and last index, then add the new node
		to the position.
		indexes of the list start from `0`.
	*/
	
	NodeDoubly *new_node = (NodeDoubly*) malloc(sizeof(NodeDoubly));
	NodeDoubly *current = (*head);

	if((*head) == NULL) return;

	for(int i = 0; i < position-1; i++)
	{
		/* traverse to the position and move the `current` node to the position */
		current = current->next;
		if(current == NULL) {
			printf("The position is invalid !\n");
			return;
		}
	}

	new_node->data = value;

	if(current->next == NULL) insertLastDoubly(&(*head), value);	// if `current` is the last position(node), then add the node at the end
	else
	{
		new_node->next = current->next;	// point the next of the new node to the node currently after the current(position) node
		new_node->next->previous = new_node;	// update the previous of the next node to point back to the new node
		current->next = new_node;	// link the current(position) node's next to the new node
		new_node->previous = current;	// set the previous of the new node to the current(position) node
	}
}

void insertAfterNodeDoubly(NodeDoubly *node_position, int value) {
	/*	insert a new node after the specified node provided by the function.
		if the node is NULL, return and exit the function; otherwise,
		allocate a new node and insert it after the specified node.
	*/

	if(node_position == NULL) return;

	NodeDoubly *new_node = (NodeDoubly*) malloc(sizeof(NodeDoubly));

	new_node->data = value;
	new_node->next = node_position->next;	// point the next of the new node to the node after the `node_position` node
	new_node->previous = node_position;	// set the previous of the new node to the `node_position` node
	node_position->next = new_node;	// update the next of the `node_position` to the new node

	// update the previous of the next node to point back to the new node, if the next of the new node isn't NULL
	if(new_node->next != NULL) new_node->next->previous = new_node;
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