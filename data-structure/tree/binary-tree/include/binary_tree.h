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
int maxNode(Node *node);
unsigned int leafQuantity(Node *node);
unsigned int nodesQuantity(Node *node);


void preorder(Node *node);
void inorder(Node *node);
void postorder(Node *node);


void run_binary_tree_example();

#endif	// BINARY_TREE
