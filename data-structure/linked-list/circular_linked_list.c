#include <stdio.h>
#include <stdlib.h>

#include "include/circular_singly_linked_list.h"


void insertBeginCircularSingly(NodeCircularSingly **head, int value) {
	/*	insert a new node at the beginning of the list, if the head is NULL, then 
		the head update to the new node and new node points to itself; otherwise,
		traverse until the last node and update the head update to the new node and the last node
		points to the new node
	*/

	NodeCircularSingly *new_node = (NodeCircularSingly*) malloc(sizeof(NodeCircularSingly));
	NodeCircularSingly *current = *head;	// pointer for traverse until the last node

	if(new_node == NULL)
	{
		printf("The Memory Couldn't Allocate !\n");
		return;
	}

	new_node->data = value;

	if(*head == NULL)
	{
		(*head) = new_node;
		new_node->next = *head;
	} else {
		while(current->next != *head) current = current->next;	// traverse until the last node
		new_node->next = *head;	// set the next pointer of the new node to the head node
		(*head) = new_node;	// set the new node as the head node
		current->next = *head;	// set the next pointer of the last node to the new head node
	}
}

void insertLastCircularSingly(NodeCircularSingly **head, int value) {
	/*	insert a new node at the end of the list, if the head is NULL(list is empty),
		then the head node update to the new node and new node points to itself; otherwise,
		traverse until the last node and the next of current last node points to the new node,
		so the new node is the new last node and at the end, the next node of the new node(new last nole)
		points to the head node.
	*/

	NodeCircularSingly *new_node = (NodeCircularSingly*) malloc(sizeof(NodeCircularSingly));
	NodeCircularSingly *current = *head;

	if(new_node == NULL)
	{
		printf("The Memory Couldn't Allocate !\n");
		return;
	}

	new_node->data = value;

	if(*head == NULL)
	{
		(*head) = new_node;
		new_node->next = *head;
	} else {
		while(current->next != *head) current = current->next;	// traverse until the last node
		current->next = new_node;	// set the next pointer of the current last node to the new node
		new_node->next = *head;	// set the next pointer of the new node(new last node) to the head node
	}
}


void deleteFirstCircularSingly(NodeCircularSingly **head) {
	if(*head == NULL) return;

	NodeCircularSingly *current = *head;
	NodeCircularSingly *temp = *head;

	if((*head)->next == *head)	// check if only one node in the list
	{
		*head = NULL;	// set head to the NULL as the list is now empty
		free(temp);	// deallocate the memory(delete) the head node(only node in the list)
		return;
	}

	while(current->next != *head) current = current->next;	// traverse until the last node
	(*head) = (*head)->next;	// update the head node to the next node of itself(second node)
	current->next = *head;	// set the next pointer of the current(last node) node to the new head node

	free(temp);	// deallocate the memopry(delete) the old head node
}

void deleteWholeListCircularSingly(NodeCircularSingly **head) {
	/* function for delete the whole list and free the memory. */

	if(*head == NULL) return;

	NodeCircularSingly *current = *head;
	NodeCircularSingly *next_node;

	while(current->next != *head)
	{
		next_node = current->next;	// store the next node
		free(current);	// deallocate the current node
		current = next_node;	// move to the next node
	}
	free(current);	// free the last node
	*head = NULL;

}


void displayCircularSingly(NodeCircularSingly **head) {
	if(*head == NULL)
    {
        printf("\nThe List Is Empty !\n");
        return;
    }

	NodeCircularSingly *current = *head;

	printf("The Elements Of The List: \n\t");
	do {
		printf("%d -> ", current->data);	// print the data of each node during traversing
		current = current->next;	// move the current node
	} while(current != *head);	// traverse on the list until the last node(the node what points to the head node)
	printf("HEAD\n");
}


int countNodesCircularSingly(NodeCircularSingly **head) {
	/* count the nodes of the list and return the total */

	NodeCircularSingly *temp = *head;
	int counter = 1;

	do {
		temp = temp->next;
		counter++;
	} while(temp->next != *head);	// traverse on the list until the last node

	return counter;
}
