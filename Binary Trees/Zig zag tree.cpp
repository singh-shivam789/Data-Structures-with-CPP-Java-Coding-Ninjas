/*
ZigZag tree
Given a binary tree, print the zig zag order. 

In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. 
This means odd levels should get printed from left to right and even level right to left.

Input format:
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. '
Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.

Constraints
Time Limit: 1 second

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output :
5
10 6
2 3
9
*/

#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    else if(root -> left == NULL && root -> right == NULL){
        cout<<root -> data;
        return;
    }
    else{
        stack<BinaryTreeNode<int>*> currentLevel;
        stack<BinaryTreeNode<int>*> nextLevel;
        currentLevel.push(root);
        bool leftToRight = true;
        while(!currentLevel.empty()){
            if(root == NULL){
                return;
            }
            BinaryTreeNode<int>* temp = currentLevel.top();
			      currentLevel.pop();
            if(temp){
                cout<<temp -> data<<" ";
                if(leftToRight){
                    if(temp -> left){
                        nextLevel.push(temp -> left);
                    }
                    if(temp -> right){
                        nextLevel.push(temp -> right);
                    }
                }
                //right to left
                else{
                    if(temp -> right){
                        nextLevel.push(temp -> right);
                    }
                    if(temp -> left){
                        nextLevel.push(temp -> left);
                    }
                }
            }
            if(currentLevel.empty()){
                cout<<"\n";
                swap(nextLevel, currentLevel);
            	  leftToRight = !leftToRight;
            }
        }
    }
}
