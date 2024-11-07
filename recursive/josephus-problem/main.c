#include <stdio.h>
#include <stdlib.h>


// the circular singly linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *initialNode(int value);
void initialCircularLinkedList(Node **head, unsigned capacity);

void displayList(Node **head);


int main() {
    Node *head = NULL;
    initialCircularLinkedList(&head, 5);
    displayList(&head);

    return 0;
}


Node *initialNode(int value) {
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

void initialCircularLinkedList(Node **head, unsigned capacity) {
    /*  initialize(create) a circular linked list with a specified number of nodes
    
        @head: a pointer to the head pointer of the list, which will point to the first node
        @capacity: the total number of nodes to create in the list

        the function initializes a circular linked list with `capacity` nodes, where each node contains
        a unique integer value starting from 1 to `capacity`.
    */
    
    Node *current;

    *head = initialNode(1);
    current = *head;

    for(int i = 2; i <= capacity; i++)  // create and link nodes from 2 up to `capacity`
    {
        current->next = initialNode(i); // initial(create) a new node with valuue `i` and link it to the `current` node
        current = current->next;    // move the current until it reaches the last node(a node with a value equal to capacity)
    }

    current->next = *head;  // set the next pointer of last node to the head node
}


int josephus_problem() {
    
}


void displayList(Node **head) {
	if(*head == NULL)
    {
        printf("\nThe List Is Empty !\n");
        return;
    }

	Node *current = *head;

	printf("The Elements Of The List: \n\t");
	do {
		printf("%d -> ", current->data);	// print the data of each node during traversing
		current = current->next;	// move the current node
	} while(current != *head);	// traverse on the list until the last node(the node what points to the head node)
	printf("HEAD\n");
}
