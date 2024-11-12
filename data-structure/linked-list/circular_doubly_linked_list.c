#include <stdio.h>
#include <stdlib.h>

#include "include/circular_doubly_linked_list.h"


NodeCircularDoubly *initializeCircularDoubly(int value) {
    NodeCircularDoubly *new_node = (NodeCircularDoubly*) malloc(sizeof(NodeCircularDoubly));

    new_node->data = value;
    new_node->next = new_node;
    new_node->previous = new_node;

    return new_node;
}

void insertBeginCircularDoubly(NodeCircularDoubly **head, NodeCircularDoubly **last, int value) {
    /*  insert a new node at the beginning of the list, if the head is NULL, then 
		the head update to the new node and new node points to itself; otherwise,
		update the head update to the new node and the next pointer of the last node
        points to the new node and also the previous pointer of the new node points to the last node.
    */

    NodeCircularDoubly *new_node = initializeCircularDoubly(value); // initialize the new node

    if(new_node == NULL)
	{
		printf("The Memory Couldn't Allocate !\n");
		return;
	}

    if(*head == NULL && *last == NULL)   // check if the list is empty
    {
        *head = *last = new_node;   // `head` and `last` both are point to the new node(the only node)
        new_node->next = new_node;  // set the next pointer of the new node to itself
        new_node->previous = new_node;  // set the previous pointer of the new node to itself
    } else {
        new_node->next = *head; // set the next pointer of the new node to the `head`
        (*head)->previous = new_node;   // set the previous pointer of the `head` to the new node

        (*head) = new_node; // update the `head` node to the new node(new node is the head now)
        (*last)->next = *head;   // set the next pointer of the last node to the new head(new node)
        (*head)->previous = *last;  // set the next pointer of the new head(new node) to the last node
    }
}

void insertLastCircularDoubly(NodeCircularDoubly **head, NodeCircularDoubly **last, int value) {
    /*	insert a new node at the end of the list, if the head and the last are NULL(list is empty),
		then the head node update to the new node and new node points to itself; otherwise,
		the next of current last node points to the new node, so the new node is the last node node and at the end,
        the next node of the new node(new last node) points to the head node,
        and the previous pointer of the head node points to the new last node(new node).
	*/

    NodeCircularDoubly *new_node = initializeCircularDoubly(value);

    if(*head == NULL && *last == NULL)  // check if the list is empty
    {
        *head = *last = new_node;   // `head` and `last` both are point to the new node(the only node)
        new_node->next = new_node;  // set the next pointer of the new node to itself
        new_node->previous = new_node;  // set the previous pointer of the new node to itself
    } else {
        (*last)->next = new_node;   // set the next pointer of the last node to the new node
        new_node->previous = *last ; // set the previous pointer of the new node to the last node(current last node)

        (*last) = new_node; // update thr `last` node to the new node(new node is the last node)
        (*head)->previous = *last;   // set the previous pointer of the head node to the new node(new last node)
        (*last)->next = *head; // set the next pointer of the new node to the head node
    }
}

void deleteWholeListCircularDoubly(NodeCircularDoubly **head) {
    /* function for delete the whole list and free the memory. */

	if(*head == NULL) return;

	NodeCircularDoubly *current = *head;
	NodeCircularDoubly *next_node;

	while(current->next != *head)
	{
		next_node = current->next;	// store the next node
		free(current);	// deallocate the current node
		current = next_node;	// move to the next node
	}
	free(current);	// free the last node
	*head = NULL;
}


void displayCircularDoubly(NodeCircularDoubly **head, NodeCircularDoubly **last) {
    if( *head == *last && *head == NULL )
    {
        printf("The List Is Empty...\n");
        return;
    }

    NodeCircularDoubly *current = *head;

    printf("The Elements Of The List: \n\t");
    printf("LAST <- ");
	do {
		printf("%d <-> ", current->data);	// print the data of each node during traversing
		current = current->next;	// move the current node
	} while(current != *head);	// traverse on the list until the last node(the node what points to the head node)
	printf("HEAD\n");
}
