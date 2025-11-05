#ifndef DOUBLY_LINKED_LIST
#define DOUNLY_LINKED_LIST

typedef struct node_doubly {
	int data;
	struct node_doubly *next;
	struct node_doubly *previous;
} NodeDoubly;

NodeDoubly *init_node_doubly(NodeDoubly **head, int value);

void insert_begin_doubly(NodeDoubly **head, int value);
void insert_last_doubly(NodeDoubly **head, int value);
void insert_position_doubly(NodeDoubly **head, int position, int value);
void insert_after_node_doubly(NodeDoubly *node_position, int value);

void delete_first_doubly(NodeDoubly **head);
void delete_last_doubly(NodeDoubly **head);
void delete_node_by_value(NodeDoubly **head, int value);
void delete_whole_list_doubly(NodeDoubly **head);

void reverse_list_doubly(NodeDoubly **head);

void display_doubly(NodeDoubly **head);


void run_doubly_linked_list_example();

#endif	// DOUBLY_LINKED_LIST
