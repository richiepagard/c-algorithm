#include <stdio.h>
#include <stdlib.h>

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
