/*
Print Level Wise
For a given a Binary Tree of type integer, print the complete information of every node, when traversed in a level-order fashion.
To print the information of a node with data D, you need to follow the exact format :

           D:L:X,R:Y

Where D is the data of a node present in the binary tree. 
X and Y are the values of the left(L) and right(R) child of the node.
Print -1 if the child doesn't exist.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. 
Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
Information of all the nodes in the Binary Tree will be printed on a different line where each node will follow a format of D:L:X,R:Y, without any spaces in between.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:
8:L:3,R:10
3:L:1,R:6
10:L:-1,R:14
1:L:-1,R:-1
6:L:4,R:7
14:L:13,R:-1
4:L:-1,R:-1
7:L:-1,R:-1
13:L:-1,R:-1

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
1:L:2,R:3
2:L:4,R:5
3:L:6,R:7
4:L:-1,R:-1
5:L:-1,R:-1
6:L:-1,R:-1
7:L:-1,R:-1
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

void printLevelWise(BinaryTreeNode<int>* root) {
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != NULL) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		cout<<front->data << ":";
		pendingNodes.pop();
		if (front->left != NULL) {
			cout << "L:" << front->left->data << ",";
			pendingNodes.push(front->left);
		}
		else {
			cout << "L:" << -1 << ",";
		}
		if (front->right != NULL) {
			cout << "R:" << front->right->data;
			pendingNodes.push(front->right);
		}
		else {
			cout << "R:" << -1;
		}
		cout << "\n";
	}
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
	printLevelWise(root);
	delete root;
}
