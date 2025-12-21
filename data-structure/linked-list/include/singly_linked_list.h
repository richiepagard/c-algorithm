#include <stdbool.h>

#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *initial_node_singly(int value);

// insertion functions
void insert_begin_singly(Node **head, Node *new_node);
void insert_last_singly(Node **head, Node *new_node);
void insert_position_singly(Node **head, Node *new_node, int position);

// deletion functions
void delete_begin_singly(Node **head);
void delete_last_singly(Node **head);
void delete_position_singly(Node **head, int position);
void delete_whole_list_singly(Node **head);

void display_singly(Node **head);
void display_reverse_singly(Node **head);

int find_maximum_singly(Node **head);
int count_node_singly(Node **head);
bool search_recursive_singly(Node **head, int data);
int find_index_recursive_singly(Node **head, int data);

Node *concatenate_two_list_singly(Node **head1, Node **head2);


void run_singly_linked_list_example();

#endif
