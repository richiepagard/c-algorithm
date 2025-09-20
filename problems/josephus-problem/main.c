#include <stdio.h>
#include <stdlib.h>


// the circular singly linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *initial_node(int value);
void initial_circular_linked_list(Node **head, unsigned capacity);
void display_list(Node **head);

int josephus_problem(Node **head);


int main() {
    Node *head = NULL;
    initial_circular_linked_list(&head, 41);
    // display_list(&head);  // uncomment it if you need to display the list

    printf("The servivor's spot on: %d\n", josephus_problem(&head));

    return 0;
}


Node *initial_node(int value) {
    /*  initializes(create) and returns a new node with the specified value provided by function.

        @value: integer, the value to set as `data` in the new node.

        returns pointer to the new node, or NULL if memory allocation fails.
    */

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

void initial_circular_linked_list(Node **head, unsigned capacity) {
    /*  initialize(create) a circular linked list with a specified number of nodes
    
        @head: a pointer to the head pointer of the list, which will point to the first node
        @capacity: the total number of nodes to create in the list

        the function initializes a circular linked list with `capacity` nodes, where each node contains
        a unique integer value starting from 1 to `capacity`.
    */
    
    Node *current;

    *head = initial_node(1);
    current = *head;

    for(int i = 2; i <= capacity; i++)  // create and link nodes from 2 up to `capacity`
    {
        current->next = initial_node(i); // initial(create) a new node with valuue `i` and link it to the `current` node
        current = current->next;    // move the current until it reaches the last node(a node with a value equal to capacity)
    }

    current->next = *head;  // set the next pointer of last node to the head node
}


int josephus_problem(Node **head) {
    /*  solve the Josephus problem, where people arranged in a circle are eliminated in steps
        until only one remains. this function returns the data of the last remaining node.

        @head: a pointer to the head of circular linked list where each node represents a person.

        the function iteratively eliminates every second node by bypassing it in the linked list.
        the process continues until only one node remains in the list. the data of the last remaining node
        is returned as the `survivor` of the Josephus problem.

        steps:
        1- initialize `suicide_spot` to the head of the list, representing the current node in the elimination sequence.
        2- iterate through the list, skipping one node(the eliminated node) and moving `suicide_spot` forward to the next node.
        3- continue until `suicide_spot` points to itselt, indicating that only that only one node remains.
        4- return the data of the last remaining node(survivor's data)
    */

    Node *suicide_spot = *head;

    while(suicide_spot->next != suicide_spot)
    {
        suicide_spot->next = suicide_spot->next->next;  // eliminate the next node by linking `suicide_spot` to the nodle after the next pointer
        suicide_spot = suicide_spot->next;  // move `suicide_spot` forward to the next node in the updated list
    }

    return suicide_spot->data;  // return the survivor's data
}


void display_list(Node **head) {
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
