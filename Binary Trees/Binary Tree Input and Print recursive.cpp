/*
Binary  Tree
A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary tree can have only 2 children, we typically name them the left and right child.

A Binary Tree node contains following parts.

Data
Pointer to left child
Pointer to right child

This is the code for the Binary Tree Class and functions to take Binary Tree input and printing it recursively.

Sample Input: 
1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1                                                                              
Here -1 indicates that we don't want to add child nodes for that node.

Sample Output: 
1:L2 R3
2:L4 R5
4:
5:L6 R7
6:
7:
3:L8
8:
*/

#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) return;
	cout << root->data <<":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}
	cout << " ";
	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << "\n";
	printTree(root->left);
	printTree(root->right);
}

BinaryTreeNode<int>* takeInput() {
	int rootData;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* left = takeInput();
	BinaryTreeNode<int>* right = takeInput();
	root->left = left;
	root->right = right;
	return root;
}

int main() {
	BinaryTreeNode<int>* root = takeInput();
	printTree(root);
}
