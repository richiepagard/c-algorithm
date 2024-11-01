#ifndef DOUBLY_LINKED_LIST
#define DOUNLY_LINKED_LIST

typedef struct node_doubly {
	int data;
	struct node_doubly *next;
	struct node_doubly *previous;
} NodeDoubly;

NodeDoubly *initialNodeDoubly(NodeDoubly **head, int value);

void insertBeginDoubly(NodeDoubly **head, int value);
void insertLastDoubly(NodeDoubly **head, int value);
void insertPositionDoubly(NodeDoubly **head, int position, int value);
void insertAfterNodeDoubly(NodeDoubly *node_position, int value);

void deleteFirstDoubly(NodeDoubly **head);
void deleteLastDoubly(NodeDoubly **head);
void deleteNodeByValue(NodeDoubly **head, int value);
void deleteWholeListDoubly(NodeDoubly **head);

void displayDoubly(NodeDoubly **head);

#endif	// DOUBLY_LINKED_LIST
