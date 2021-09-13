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

#include<climits>
class Container{
    public:
    TreeNode<int>* largest;
    TreeNode<int>* secondLargest;

    Container(TreeNode<int>* first, TreeNode<int>* second){
        this -> largest = first;
        this -> secondLargest = second;
    }
};

Container* getSecondLargestNodeHelper(TreeNode<int>* root){
    if(root == NULL){
        return new Container(NULL, NULL);
    }
    else if(root -> children.size() == 0){
        return new Container(root, NULL);
    }
    else{
        Container* ans = new Container(root, NULL);
        for(int i=0; i<root -> children.size(); i++){
            Container* recAns = getSecondLargestNodeHelper(root -> children[i]);
            if (recAns->largest->data > ans->largest->data) {
                if (recAns->secondLargest == NULL) {
                    ans->secondLargest = ans->largest;
                    ans->largest = recAns->largest;
                } 
                else {
                    if (recAns->secondLargest->data > ans->largest->data) {
                        ans->secondLargest = recAns->secondLargest;
                        ans->largest = recAns->largest;
                    } 
                    else {
                        ans->secondLargest = ans->largest;
                        ans->largest = recAns->largest;
                    }
                }
            } 
            else {
                if (ans->largest->data != recAns->largest->data && (ans->secondLargest == NULL || recAns->largest->data > ans->secondLargest->data)) {
                    ans->secondLargest = recAns->largest;
                }
            }
        }
        return ans;
    }
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    return getSecondLargestNodeHelper(root)->secondLargest;
}
