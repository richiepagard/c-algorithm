#ifndef LINKED_LIST
#define LINKED_LIST

// Singly Linked List
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *initialNodeSingly(int value);
void insertBeginSingly(Node **head, Node *new_node);
void insertLastSingly(Node **head, Node *new_node);
void displaySingly(Node **head);

#endif
