/*
  Print path from root to a given node in a binary tree
  Given a binary tree with distinct nodes(no two nodes have the same have data values). The problem is to print the path from root to a given node x.
  Example: 

  Input :        1
               /   \
              2     3
             / \   /  \
            4   5  6   7

for x = 5, 
Output : 1 2 5 
*/

#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
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

vector<int>* rootToNodePath(BinaryTreeNode<int>* root, int data) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == data) {
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	
	vector<int>* leftOutput = rootToNodePath(root->left, data);
	vector<int>* rightOutput = rootToNodePath(root->right, data);
	if (leftOutput != NULL) {
		leftOutput->push_back(root->data);
		return leftOutput;
	}
	
	if (rightOutput != NULL) {
		rightOutput->push_back(root->data);
		return rightOutput;
	}
	else {
		return NULL;
	}
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
	cout << endl;
	cout << "Enter destination node data" << endl;
	int data;
	cin >> data;
	cout << endl;
	vector<int>* v = rootToNodePath(root, data);
	for (int i = 0; i < v->size(); i++) {
		cout << v->at(i) << " ";
	}
	delete v;
}
