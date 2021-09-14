#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	struct TreeNode * left;
	struct TreeNode * right;
	int val;
};



struct TreeNode* newNode(int data)
{
    // Allocate memory for new node
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
 
    // Assign data to this node
    node->val = data;
 
    // Initialize left and
    // right children as NULL
    node->left = NULL;
    node->right = NULL;
    return (node);
}
 

int degrees_tree(struct TreeNode* root)
{
	if(root == NULL) return 0;

	return degrees_tree(root->left) + degrees_tree(root->right) +1;		
}

int sum_of_degrees(struct TreeNode* root)
{
	int ver = degrees_tree(root);
	
	return (ver-1)*2;
}

int main()
{
	struct TreeNode* root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);

	root->left->left = newNode(4);
	root->left->right = newNode(5);

	root->right->left = newNode(6);
	root->right->right = newNode(7);

	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);
	
	root->left->right->left = newNode(10);

	printf("Sum of degree of the vertices %d\n", sum_of_degrees(root));

}