/*
Diameter of a Binary Tree
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 

For a given Binary Tree of integers, find and return the diameter of the tree.

Example:
                        10
                      /      \
                    20      30
                   /    \
                 40    50
Diameter of the given tree is 3. 

Complexity of the code: O(n), where n is the number of nodes in the tree.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. 
Since -1 is used as an indication whether the left or right node data exist for root, 
it will not be a part of the node data.

Output Format:
The first and the only line of output will be the diameter of the given input tree.

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

class Pair {
public:
	int height;
	int diameter;
	
	Pair() {
		height = 0;
		diameter = 0;
	}

	Pair(int h, int d) {
		height = h;
		diameter = d;
	}
};

Pair heightDiameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		Pair p;
		return p;
	}

	Pair leftans = heightDiameter(root->left);
	Pair rightans = heightDiameter(root->right);
	int height = 1 + max(leftans.height, rightans.height);
	int diameter = max(leftans.height + rightans.height, max(leftans.diameter, rightans.diameter));
	Pair ans(height, diameter);
	return ans;
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
	Pair ans = heightDiameter(root);
	cout << ans.diameter << "\n";
	delete root;
}
