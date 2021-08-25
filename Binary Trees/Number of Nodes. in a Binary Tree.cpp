/*

Number of Nodes in a Binary Tree

For a given Binary Tree of type integer find the number of nodes in the tree.

Input Format:
The first line of each test case contains elements of the first tree in the level order form. 
The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.


For example, the input for the tree depicted in the below image would be:
1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1

Explanation:
Level 1:
The root node of the tree is 1

Level 2:
Left child of 1 = 2
Right child of 1 = 3

Level 3:
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4:
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5:
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. 
The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.
The input ends when all nodes at the last level are null(-1).

Note:
The above format was just to provide clarity on how the input is formed for a given tree.
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

Output Format:
The only line of output prints the number of nodes in the tree.

Constraints:
1 <= N <= 10^5

Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec.

Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:
9
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

int numNodes(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + numNodes(root->left) + numNodes(root->right);
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
	cout << numNodes(root);
	delete root;
}
