#ifndef BINARY_TREE
#define BINARY_TREE

#include <stdbool.h>

typedef struct tree_node {
    /* the structure for a binary tree */

    int data;
    struct tree_node *left;  // pointer to the left child
    struct tree_node *right; // pointer to the right child
} TreeNode;


TreeNode *init_tree_node(int value);

void delete_tree(TreeNode **node);

int height_node(TreeNode *node);
int max_node(TreeNode *node);
unsigned int leafQuantity(TreeNode *node);
unsigned int nodesQuantity(TreeNode *node);

int identical(TreeNode *node1, TreeNode *node2);
bool is_complete(TreeNode *root, int capacity);
int find_level(TreeNode *node, int data, int level);
bool ancestors(TreeNode *node, int data);
TreeNode *LCA(TreeNode *root, int x, bool x_flag, int y, bool y_flag);
TreeNode *LCA_widtch_defaultDefault(TreeNode *root, int x, int y);
TreeNode *left_most(TreeNode *root);



void run_binary_tree_example();

#endif	// BINARY_TREE
