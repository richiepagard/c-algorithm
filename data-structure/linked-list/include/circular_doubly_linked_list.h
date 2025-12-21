#ifndef CIRCULAR_DOUBLY_LINKED_LIST
#define CIRCULAR_DOUBLY_LINKED_LIST

typedef struct node_circular_doubly {
	int data;
	struct node_circular_doubly *next;
	struct node_circular_doubly *previous;
} NodeCircularDoubly;

NodeCircularDoubly *initialize_circular_doubly(int value);
void insert_begin_circular_doubly(NodeCircularDoubly **head, NodeCircularDoubly **last, int value);
void insert_last_circular_doubly(NodeCircularDoubly **head, NodeCircularDoubly **last, int value);

void delete_first_circular_doubly(NodeCircularDoubly **head, NodeCircularDoubly **last);
void delete_last_circular_doubly(NodeCircularDoubly **head, NodeCircularDoubly **last);
void delete_whole_list_circular_doubly(NodeCircularDoubly **head, NodeCircularDoubly **last);

void display_circular_doubly(NodeCircularDoubly **head, NodeCircularDoubly **last);


void run_circular_doubly_linked_list_example();

#endif // CIRCULAR_DOUBLY_LINKED_LIST
