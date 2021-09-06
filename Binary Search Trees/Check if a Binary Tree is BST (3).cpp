/*
Check if a Binary Tree is BST

Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.

Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. 
Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :
The first and only line of output contains either true or false.
Constraints :
Time Limit: 1 second

Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1

Sample Output 1 :
true

Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

Sample Output 2 :
false
*/

/*
  Time Complexity: O(n)
*/

#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

bool isBSTHelper(BinaryTreeNode<int> *root, int max = INT_MAX, int min = INT_MIN){
  if(root == NULL) return true;
	if(root -> data > max || root -> data < min){
        return false;
    }
    bool leftAns = isBSTHelper(root -> left, root -> data - 1, min);
    bool rightAns = isBSTHelper(root -> right, max, root -> data);
    return leftAns && rightAns;
}

bool isBST(BinaryTreeNode<int> *root) {
	return isBSTHelper(root);
}

BinaryTreeNode<int>* takeInput() {
	int rootData;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while (!q.empty()) {
		BinaryTreeNode<int>* currentNode = q.front();
		q.pop();
		int leftChild, rightChild;

		cin >> leftChild;
		if (leftChild != -1) {
			BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
			currentNode->left = leftNode;
			q.push(leftNode);
		}

		cin >> rightChild;
		if (rightChild != -1) {
			BinaryTreeNode<int>* rightNode =
				new BinaryTreeNode<int>(rightChild);
			currentNode->right = rightNode;
			q.push(rightNode);
		}
	}
	return root;
}

int main() {
	BinaryTreeNode<int>* root = takeInput();
	cout << (isBST(root) ? "true" : "false");
}
