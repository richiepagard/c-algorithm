#ifndef BINARY_TREE
#define BINARY_TREE

#include <stdbool.h>

typedef struct tree_node {
    /* the structure for a binary tree */

    int data;
    struct tree_node *left;  // pointer to the left child
    struct tree_node *right; // pointer to the right child
} TreeNode;


TreeNode *initializeTreeNode(int value);

void deleteTree(TreeNode **node);

int heightNode(TreeNode *node);
int maxNode(TreeNode *node);
unsigned int leafQuantity(TreeNode *node);
unsigned int nodesQuantity(TreeNode *node);

int identical(TreeNode *node1, TreeNode *node2);
bool isComplete(TreeNode *root, int capacity);
int findLevel(TreeNode *node, int data, int level);
bool ancestors(TreeNode *node, int data);



void run_binary_tree_example();

#endif	// BINARY_TREE
