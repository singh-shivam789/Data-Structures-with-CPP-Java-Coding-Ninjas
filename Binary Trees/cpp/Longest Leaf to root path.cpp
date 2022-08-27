/*
Longest Leaf to root path
Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.

Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)

Line 1 : Binary Tree 1 (separated by space)

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 
Sample Output 1 :
9
3
6
5
*/

vector<int>* longestPath(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return NULL;
    } 
    else if(!root -> left && !root -> right){
        vector<int>* ans = new vector<int>();
        ans -> push_back(root -> data);
        return ans;
    }
    else{
        if(!root -> left){
            vector<int>* rightAns = longestPath(root -> right);
            rightAns -> push_back(root -> data);
            return rightAns;
        }
        else if(!root -> right){
            vector<int>* leftAns = longestPath(root -> left);
            leftAns -> push_back(root -> data);
            return leftAns;
        }
        else{
            vector<int>* rightAns = longestPath(root -> right);
            vector<int>* leftAns = longestPath(root -> left);
            if(leftAns -> size() >= rightAns -> size()){
                leftAns -> push_back(root -> data);
                delete rightAns;
                return leftAns;
            }
            else{
                rightAns -> push_back(root -> data);
                delete leftAns;
                return rightAns;
            }
        }
    }
}

