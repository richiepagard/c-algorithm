#ifndef TRAVERSE_BINARY_TREE
#define TRAVERSE_BINARY_TREE

#include "binary_tree.h"    // use for get the Node structure


void inorder_iterator(TreeNode *root);
void preorder_iterator(TreeNode *root);
void postorder_iterator(TreeNode *root);

void levelorder(TreeNode *root, int capacity);

void inorder_recursive(TreeNode *node);
void preorder_recursive(TreeNode *node);
void postorder_recursive(TreeNode *node);


#endif  // TRAVERSE_BINARY_TREE
