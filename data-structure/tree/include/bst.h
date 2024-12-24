#ifndef BST
#define BST

#include <stdbool.h>
#include "binary_tree.h"

TreeNode* insertBST(TreeNode* root, int value);
TreeNode* insertBSTIterator(TreeNode* root, int value);

bool searchNodeBST(TreeNode* root, int key);



void run_bst_example();

#endif	// BST
