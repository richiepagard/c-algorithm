#ifndef BST
#define BST

#include <stdbool.h>
#include "binary_tree.h"

TreeNode* insertBSTRecursive(TreeNode* root, int value);
TreeNode* insertBST(TreeNode* root, int value);

TreeNode* searchNodeBSTRecursive(TreeNode* root, int key);
bool searchNodeBST(TreeNode* root, int key);



void run_bst_example();

#endif	// BST
