#ifndef BST
#define BST

#include <stdbool.h>
#include "binary_tree.h"

TreeNode* insert_bst_recursive(TreeNode* root, int value);
TreeNode* insert_bst(TreeNode* root, int value);

TreeNode* search_node_bst_recursive(TreeNode* root, int key);
bool search_node_bst(TreeNode* root, int key);

TreeNode* find_min(TreeNode* root);
TreeNode* delete_node_bst(TreeNode* root, int key);

void find_predecessor_successor(TreeNode* root, TreeNode** predecessor, TreeNode** successor, int key);



void run_bst_example();

#endif	// BST
