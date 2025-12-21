#include <stdio.h>
#include <stdlib.h>

#include "../include/doubly_linked_list.h"


NodeDoubly *initial_node_doubly(NodeDoubly **head, int value) {
	/*	initialize a new node, if the list is empty, then the `head` will update to the new node,
		but if the list isn't empty, the new node will set to the last node. */

	NodeDoubly *new_node = (NodeDoubly*) malloc(sizeof(NodeDoubly));	// initialize a new node

	new_node->data = value;
	new_node->next = NULL;

	if(*head == NULL)
	{
		/*	if the `head` node is NULL(the list is empty), the `previous` of the new node
			will set to the NULL and the `head` will update to the new node. */
		insert_begin_doubly(&(*head), value);
	} else {
		/* if the list isn't empty, the new node will set to the last node  */
		insert_last_doubly(&(*head), value);
	}
}


void insert_begin_doubly(NodeDoubly **head, int value) {
	/*	insert at the beginning of the list
		first node is the node that the `previous` points to the NULL */

	NodeDoubly *new_node = (NodeDoubly*) malloc(sizeof(NodeDoubly));

	new_node->data = value;
	new_node->next = (*head);	// the new node's `next` is points to the current `head` node
	new_node->previous = NULL;

	if( (*head) != NULL ) (*head)->previous = new_node;	// the current `head` node's previous is points to the new node
	(*head) = new_node;	// the new node is set to the `head` node
}

void insert_last_doubly(NodeDoubly **head, int value) {
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

void insert_position_doubly(NodeDoubly **head, int position, int value) {
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

	if(current->next == NULL) insert_last_doubly(&(*head), value);	// if `current` is the last position(node), then add the node at the end
	else
	{
		new_node->next = current->next;	// point the next of the new node to the node currently after the current(position) node
		new_node->next->previous = new_node;	// update the previous of the next node to point back to the new node
		current->next = new_node;	// link the current(position) node's next to the new node
		new_node->previous = current;	// set the previous of the new node to the current(position) node
	}
}

void insert_after_node_doubly(NodeDoubly *node_position, int value) {
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


void delete_first_doubly(NodeDoubly **head) {
	/* delete the first node of the list and deallocate the memory */
	
	if(*head == NULL) return;

	NodeDoubly *temp = *head;

	(*head) = (*head)->next;	// update the `head` to the next node of the current head
	if(*head != NULL) (*head)->previous = NULL;	// set the previous of the new `head` to the NULL, if the new `head` isn't NULL

	free(temp);	// deallocate the memory
}

void delete_last_doubly(NodeDoubly **head) {
	/* delete the last node of the list and deallocate the memory */

	if(*head == NULL) return;

	NodeDoubly *temp = *head;

	while(temp->next != NULL) temp = temp->next;	// traverse to the last node
	temp->previous->next = NULL;	// update the next of the previous node(last node) to point to the NULL

	free(temp);	// deallocate the memory
}

void delete_node_by_value(NodeDoubly **head, int value) {
	/*	delete a specified node by a specified value provided by the function.

		if the node is NULL, return and exit the function; otherwise,
		if the value is the value of the first node, then delete the node, but
		if the value is the value of the last node, then delete the node, but finally,
		if the value is between first and last node, traverse to the list and find the node 
		with that value and delete the node and also deallocate the memory of the node.
	 */

	if((*head) == NULL) return;

	NodeDoubly *temp = *head;	// the temporary node for deallocating the deleted node
	NodeDoubly *current = *head;	// the `current` node is the traversing node for traverse to the list on each node

	if((*head)->data == value)
	{
		delete_first_doubly(&(*head));
		return;
	}

	while(current->next->next != NULL)	// // traverse to the list until the previous node of the last node
	{
		if(current->next->data == value) {
			temp = current->next;	// update the `temp` to the next node of the `current` node
			current->next = temp->next;	// update the next node of the `current` to the next node of the `temp`
			temp->next->previous = current;	// update the previous of the next node to point back to the `current` node
			free(temp);	// deallocate the memory of the `temp` node
			return;
		}
		current = current->next;	// move the current
	}

	if(current->next->data == value) delete_last_doubly(&(*head));
}

void delete_whole_list_doubly(NodeDoubly **head) {
	/*	function for delete the whole list and free the memory.
	 	use the recursive way.*/

	if(*head == NULL) return;

	delete_whole_list_doubly(&(*head)->next);
	free(*head);

	*head = NULL;
}


void display_doubly(NodeDoubly **head) {
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

void reverse_list_doubly(NodeDoubly **head) {
	NodeDoubly *temp, *current;	// temp: temporary node for helper pointer and change the head after reverse. current: traverse to the list on each node

	temp = *head;	// set temp to the current head node
	current = temp->next;
	temp->next = NULL;	// the next of temporary node set to the NULL
	temp->previous = current;	// update the previous node of the temporary node to the current second node

	while(current != NULL)
	{
		current->previous = current->next;	// set the previous pointer of the current node to point to its next node during traversal
		current->next = temp;	// set the next pointer of the current node to the temporary node (current head) during traversal
		temp = current;	// move the temporary node to the current node
		current = current->previous;	// update the current node to its previous pointer
	}
	(*head) = temp;	// set the temporary node as the head node after traversal
}
