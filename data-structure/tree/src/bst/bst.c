#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/binary_tree.h"


TreeNode* insertBSTRecursive(TreeNode* root, int value) {
	if(root == NULL) return initializeTreeNode(value);
	if(value < root->data)
	{
		root->left = insertBSTRecursive(root->left, value);
	}
	if(value > root->data)
	{
		root->right = insertBSTRecursive(root->right, value);
	}

	return root;
}

TreeNode* insertBST(TreeNode* root, int value) {
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

TreeNode* searchNodeBSTRecursive(TreeNode* root, int key) {
	/*	function look at the special node with the key that provided by funciton and return it,

		check if the root is null or the data of the root is equal to the key provided by function,
		return root node.
		check if the key less than root's data, call the function(recursively) for the left node.
		otherwise, call the function(recursively) for the right node.
	*/
	if(root == NULL || root->data == key) return root;
	if(key < root->data) return searchNodeBSTRecursive(root->left, key);
	else return searchNodeBSTRecursive(root->right, key);
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
