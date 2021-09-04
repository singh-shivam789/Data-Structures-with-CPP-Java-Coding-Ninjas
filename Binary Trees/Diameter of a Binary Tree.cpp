/*
Diameter of a Binary Tree

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 
Find and return the diameter of a binary tree.

Complexity : O(n * h), where n is the number of nodes in the tree, 
and h is the height of the tree.

Input: 
1 2 3 4 5 -1 -1 
6 -1 
-1 7 
8 -1 
-1 9
-1 -1 -1 -1 

Output: 
6
*/

#include<iostream>
#include<queue>
#include<utility>
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

int height(BinaryTreeNode<int>* root) {
	if (root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL) return 0;
	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));
}

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
			front->left = leftChild;
			pendingNodes.push(leftChild);
		}
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
			front->right = rightChild;
			pendingNodes.push(rightChild);
		}
	}
	return root;
}

int main() {
  BinaryTreeNode<int>* root = takeInputLevelWise();
  cout<<diameter(root)<<endl;
  delete root;
}
