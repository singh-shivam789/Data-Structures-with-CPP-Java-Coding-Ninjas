/*
Generic trees are a collection of nodes where each node is a data structure that consists of records and a list of references to its 
children(duplicate references are not allowed). Unlike the linked list, each node stores the address of multiple nodes. 
Every node stores address of its children and the very first node’s address will be stored in a separate pointer called root.
The Generic trees are the N-ary trees which have the following properties: 
    1. Many children at every node.
    2. The number of nodes for each node is not known in advance.
            
Following is the code of Tree class and functions for taking user input level wise (level order) and printing it recursively.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class TreeNode {
public:
	T data;
	vector<TreeNode<T>*> children;
	TreeNode(T data) {
		this->data = data;
	}
};

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data!" << "\n";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int n;
		cout << "Enter the number of children of :- " << front->data << "\n";
		cin >> n;
		for (int i = 0; i < n; i++) {
			int childData;
			cout << "Enter the " << i + 1 << "th child of :- " << front->data << "\n";
			cin >> childData;
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			front->children.push_back(childNode);
			pendingNodes.push(childNode);
		}
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ": ";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data<<", ";
	}
	cout << "\n";
	for (int i = 0; i < root->children.size(); i++) {
		printTree(root->children[i]);
	}
} 

int main() {
	TreeNode<int>* root = takeInputLevelWise();
	printTree(root);
}
