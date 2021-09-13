/*
Second Largest Element In Tree
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.

Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. 
The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1 :
40
*/

#include <utility>
pair <TreeNode<int>*, TreeNode<int>*> getSecondLargestNodeHelper(TreeNode<int>* root){
    if(root == NULL){
        pair <TreeNode<int>*, TreeNode<int>*> ans;
        ans.first = NULL;
        ans.second = NULL;
    }

    pair <TreeNode<int>*, TreeNode<int>*> ans;
    ans.first = root;
    ans.second = NULL;
    for(int i=0; i<root -> children.size(); i++){
        pair <TreeNode<int>*, TreeNode<int>*> recAns = getSecondLargestNodeHelper(root -> children[i]);
        if(recAns.first -> data > ans.first -> data){
            if(recAns.second == NULL){
				ans.second = ans.first;
                ans.first = recAns.first;
            }
            else{
				if(recAns.second -> data > ans.first -> data){
                    ans.second = recAns.second;
                    ans.first = recAns.first;
                }
                else{
                    ans.second = ans.first;
                    ans.first = recAns.first;
                }
            }
        }
        else{
            if(recAns.first -> data != ans.first -> data && (ans.second == NULL || ans.second -> data < recAns.first -> data)){
                ans.second = recAns.first;
            }
        }
    }
    return ans;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    return getSecondLargestNodeHelper(root).second;
}
