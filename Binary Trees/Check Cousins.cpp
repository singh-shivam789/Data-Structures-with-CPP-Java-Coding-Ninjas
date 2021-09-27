/*
Check cousins

Given the binary Tree and two nodes say ‘p’ and ‘q’. 
Determine whether the two nodes are cousins of each other or not. 
Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
Do it in O(n).

Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Line 2 : integer value of p 
Line 3 : Integer value of q

Output format :
true or false

Constraints :
1 <= N <= 10^5

Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4

Sample Output :
true
*/

#include<iostream>
using namespace std;
int depth(BinaryTreeNode<int> *root, int node){
	if(root == NULL)
		return -1;
	if(node == root->data)
		return 0;
	int left = depth(root->left, node);
	if(left != -1)
		return left + 1;
	else {
		int right = depth(root->right, node);
		if(right != -1)
			return right + 1;
		else 
			return -1;
	}
}

bool isSibling(BinaryTreeNode<int> *root, int p, int q){
    if(root == NULL){
        return false;
    }
    else if(root -> left == NULL && root -> right == NULL){
        return false;
    }
    else if(root -> left != NULL && root -> right != NULL){
        if(root -> left -> data == p && root -> right -> data == q){
            return true;
        }
        else if(root -> left -> data == q && root -> right -> data == p){
            return true;
        }
        else{
			return isSibling(root -> left, p, q) ||  isSibling(root -> right, p, q);
        }
    }
    else{
        if(root -> left == NULL){
            return isSibling(root -> right, p, q);
        }
        else{
            return isSibling(root -> left, p, q);
        }
    }
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
	if(root == NULL){
        return false;
    }
  return ((depth(root, p) == depth(root, q)) && (!isSibling(root, p, q))); 
}
