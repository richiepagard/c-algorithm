#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} Node;


Node *initializeNode(int value);

void deleteTree(Node **node);

int heightNode(Node *node);
int leafQuantity(Node *node);
int nodesQuantity(Node *node);



void run_binary_tree_example();

#endif	// BINARY_TREE
