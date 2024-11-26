#ifndef TRAVERSE_BINARY_TREE
#define TRAVERSE_BINARY_TREE

#include "binary_tree.h"    // use for get the Node structure


void inorderIterator(TreeNode *root);
void preorderIterator(TreeNode *root);
void postorderIterator(TreeNode *root);

void levelorder(TreeNode *root, int capacity);

void inorderRecursive(TreeNode *node);
void preorderRecursive(TreeNode *node);
void postorderRecursive(TreeNode *node);


#endif  // TRAVERSE_BINARY_TREE
