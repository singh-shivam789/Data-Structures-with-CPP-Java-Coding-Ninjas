/*
Print Nodes at level K

Given a root of a tree, and an integer k. Print all the nodes which are at k distance from root. 

Input Format:
The first line of input contains data of the nodes of the tree in level order form. 
The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. 
The data of the nodes of the tree is separated by space.  

The second line of input contains value of the K.

Output Format :
The first and only line of output prints the height of the given generic tree.

Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
2

Sample Output 1:

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

void printNodesAtLevelK(TreeNode<int>* root, int k) {
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root -> data<<"\n";
        return;
    }
    else{
        for(int i=0; i<root->children.size(); i++){
            printNodesAtLevelK(root->children[i], k-1);
        }
    }
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int k;
    cin>>k;
    printNodesAtLevelK(root, k);
}
