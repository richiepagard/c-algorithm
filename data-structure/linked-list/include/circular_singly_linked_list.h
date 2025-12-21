#ifndef CIRCULAR_SINGLY_LINKED_LIST
#define CIRCULAR_SINGLY_LINKED_LIST

typedef struct node_circular_singly {
	int data;
	struct node_circular_singly *next;
} NodeCircularSingly;


void insert_begin_circular_singly(NodeCircularSingly **head, int value);
void insert_last_circular_singly(NodeCircularSingly **head, int value);

void delete_first_circular_singly(NodeCircularSingly **head);
void delete_last_circular_singly(NodeCircularSingly **head);
void delete_whole_list_circular_singly(NodeCircularSingly **head);

void display_circular_singly(NodeCircularSingly **head);

int count_nodes_circular_singly(NodeCircularSingly **head);


void run_circular_singly_linked_list_example();

#endif	// CIRCULAR_SINGLY_LINKED_LIST
