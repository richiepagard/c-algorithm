#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/binary_tree.h"


TreeNode* insertBST(TreeNode* root, int value) {
	if(root == NULL) return initializeTreeNode(value);
	if(value < root->data)
	{
		root->left = insertBST(root->left, value);
	}
	if(value > root->data)
	{
		root->right = insertBST(root->right, value);
	}

	return root;
}

TreeNode* insertBSTIterator(TreeNode* root, int value) {
	if(root == NULL) return initializeTreeNode(value);

	TreeNode* current = root;
	TreeNode* parent = NULL;

	while(current != NULL) {	// traverse on the tree until find the correct position
		parent = current;	// keep track of the parent node

		if(value < current->data) current = current->left;
		else if(value > current->data) current = current->right;
		else return root;	// value already exists, return the root without any insertion
	}

	// create a new node and attach it to the appropriate parent node
	TreeNode* new_node = initializeTreeNode(value);

	if(value < parent->data) parent->left = new_node;
	else parent->right = new_node;

	return root;
}

bool searchNodeBST(TreeNode* root, int key) {
	TreeNode* current = root;

	while(current != NULL)
	{
		if(key < current->data) current = current->left;
		else if(key > current->data) current = current->right;
		else return true;
	}

	return false;
}
