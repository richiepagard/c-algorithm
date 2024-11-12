#ifndef CIRCULAR_SINGLY_LINKED_LIST
#define CIRCULAR_SINGLY_LINKED_LIST

typedef struct node_circular_singly {
	int data;
	struct node_circular_singly *next;
} NodeCircularSingly;


void insertBeginCircularSingly(NodeCircularSingly **head, int value);
void insertLastCircularSingly(NodeCircularSingly **head, int value);

void deleteFirstCircularSingly(NodeCircularSingly **head);
void deleteLastCircularSingly(NodeCircularSingly **head);
void deleteWholeListCircularSingly(NodeCircularSingly **head);

void displayCircularSingly(NodeCircularSingly **head);

int countNodesCircularSingly(NodeCircularSingly **head);


void run_circular_singly_linked_list_example();

#endif	// CIRCULAR_SINGLY_LINKED_LIST
