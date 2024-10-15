#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "linked_list.h"


Node *initialNodeSingly(int value) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL)
    {
        printf("Couldn't Allocate !\n");
        return NULL;
    } else {
        new_node->data = value;
        new_node->next = NULL;
        return new_node;
    }
}


void insertBeginSingly(Node **head, Node *new_node) {    
    if(*head == NULL)
    {
        // if the list is empty, the new node is the head node
        *head = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = *head; // the new node point to the current head node
        *head = new_node;   // the new node become to the head node
    }
}

void insertLastSingly(Node **head, Node *new_node) {
    Node *current = *head;

    if(*head == NULL)
    {
        // if the list is empty, the new node is the head node
        *head = new_node;
        new_node->next = NULL;
    } else {
        while(current->next != NULL) current = current->next;   // traverse to the last node
        new_node->next = NULL;  // the next of new node point to the NULL, because this node is the last node
        current->next = new_node;   // the old last node, point to the new node
    }
}

void insertPositionSingly(Node **head, Node *new_node, int position) {
    int counter = 0;
    Node *current = *head;
	Node *previous;

    while(current != NULL)
    {
        current = current->next;
        counter++;
    }

    if(position == 0) insertBeginSingly(head, new_node);	// insert at first position
	else if(position > 0 && position <= counter)	// if position between 1 to last node
	{
		current = *head;
		for(int i = 0; i < position; i++)
		{
			previous = current;
			current = current->next;	// move the current node
		}
		// set the new node position
		previous->next = new_node;
		new_node->next = current;
	} else {
		printf("Position Out Of Range...\n");
	}
}


void deleteBeginSingly(Node **head) {
    if(*head == NULL) return;
    else
    {
        Node *current = *head;

        *head = current->next; // the `head` changes to the second node
        free(current); // free the memory of `current`
    }
}

void deleteLastSingly(Node **head) {
    if(*head == NULL) return;
    else
    {
        Node *current = *head, *previous = *head;

        while(current->next != NULL)
        {
            /* traverse until the node points to the NULL */

            previous = current; // save the previous node of the `current` node
            current = current->next;    // move the `current` to the next node
        }
        previous->next = NULL;  // the previous node points to the NULL
        free(current);  // free the memory of `current`
    }
}

void deletePositionSingly(Node **head, int position) {
    int counter = 0;

    if(*head == NULL) return;

    Node *current = *head;
	Node *previous;
    if(position == 0) deleteBeginSingly(head);  // delete the first node
    else
    {
        while(current != NULL)
        {
            current = current->next;    // move the `current` to the next node
            counter++;
        }
        if(position > 0 && position <= counter)
        {
            current = *head;    // rewrite the `current` to the `head` node
            for(int i = 0; i < position; i++)
            {
                previous = current; // set the `current` previous node to the previous
                current = current->next;    // move the `current` to the next node
            }
            previous->next = current->next; // the `previous` point to the next node of the `current` node
        } else {
		    printf("Position Out Of Range...\n");
	    }

        free(current);  // free the memoty of `current`
    }

}

void deleteWholeListSingly(Node **head) {
	/* function for delete the whole list and free the memory.
	 * use the recursive way.*/

	if(*head == NULL) return;

	deleteWholeListSingly(&(*head)->next);
	free(*head);
}



void displaySingly(Node **head) {
    Node *temp;
    temp = *head;

    if(*head == NULL)
    {
        printf("The List Is Empty !\n");
        return;
    }

    printf("The Elements Of The List: \n");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayReverseSingly(Node **head) {
    if(*head == NULL) return;

    displayReverseSingly(&(*head)->next);
    printf("%d -> ", (*head)->data);
}


int findMaximumSingly(Node **head) {
    /* find the maximum node's data and return it */

    int maximum = INT_MIN;

    if(*head == NULL) return -1;    // if list is empty, return `-1`

    Node *current = *head;
    while(current != NULL)
    {
        // set `current` data to the `maximum` if current data is greatr than maximum
        if(current->data > maximum) maximum = current->data;
        current = current->next;    // move the `current` to the next node
    }

    return maximum;
}

int countNode(Node **head) {
	/* count the nodes of the list and return it  */

	if(*head == NULL) return 0;
	else return(1 + countNode(&(*head)->next));
}

