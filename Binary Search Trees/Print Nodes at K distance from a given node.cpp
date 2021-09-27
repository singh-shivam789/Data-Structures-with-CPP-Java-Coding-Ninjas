/*
Print nodes at distance k from node

You are given a Binary Tree of type integer, a target node, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.

Example:
For a given input tree(refer to the tree below):

      3
    /    \
   5      1
  / \    / \ 
 6   2  0   8
    / \
   7   4
   
1. Target Node: 5
2. K = 2


Starting from the target node 5, the nodes at distance K are 7 4 and 1.

Input Format:
The first line of input will contain the node data, all separated by a single space. 
Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains two integers separated by a single space, representing the value of the target node and K, respectively.

Output Format:
All the node data at distance K from the target node will be printed on a new line.
The order in which the data is printed doesn't matter.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.
Time Limit: 1 sec

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3 1

Sample Output 1:
9
6

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
3 3

Sample Output 2:
4
5
*/

/*
    Time complexity: O(N)
    Space complexity: O(H)

    where N is the number of nodes in the input binary tree and
    H is the height of the input binary tree
*/

#include <iostream>
void printNodesAtKDistance(BinaryTreeNode<int> *root, int k){
    if(root == NULL || k < 0){
        return;
    }    
    else if(k == 0){
        cout<<root -> data<<"\n";
        return;
    }
    else{
        printNodesAtKDistance(root -> left, k-1);
        printNodesAtKDistance(root -> right, k-1);
    }
}

int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int node, int k){
    if(root == NULL){
        return -1;
    }
    else if(root -> data == node){
        printNodesAtKDistance(root, k);
        return 0;
    }
    
    int ld = nodesAtDistanceKHelper(root -> left, node, k);
    if(ld != -1){
        if(ld + 1 == k){
            cout<<root -> data<<"\n";
        }
        else{
            printNodesAtKDistance(root -> right, k - ld - 2);
        }
        return ld + 1;
    }
    
    int rd = nodesAtDistanceKHelper(root -> right, node, k);
    if(rd != -1){
        if(rd + 1 == k){
            cout<<root -> data<<"\n";
        }
        else{
            printNodesAtKDistance(root->left, k - rd - 2);
        }
        return rd + 1;
    }
    
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    nodesAtDistanceKHelper(root, node, k); 
}
