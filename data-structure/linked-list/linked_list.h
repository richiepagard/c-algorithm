#include <stdbool.h>

#ifndef LINKED_LIST
#define LINKED_LIST

// Singly Linked List
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *initialNodeSingly(int value);

// insertion functions
void insertBeginSingly(Node **head, Node *new_node);
void insertLastSingly(Node **head, Node *new_node);
void insertPositionSingly(Node **head, Node *new_node, int position);
// deletion functions
void deleteBeginSingly(Node **head);
void deleteLastSingly(Node **head);
void deletePositionSingly(Node **head, int position);
void deleteWholeListSingly(Node **head);

void displaySingly(Node **head);
void displayReverseSingly(Node **head);

int findMaximumSingly(Node **head);
int countNodeSingly(Node **head);
bool searchRecursiveSingly(Node **head, int data);
int findIndexRecursiveSingly(Node **head, int data);

Node *concatenateTwoListSingly(Node **head1, Node **head2);
// End Singly Linked List

#endif
