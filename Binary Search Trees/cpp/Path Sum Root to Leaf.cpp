/*
Path Sum Root to Leaf

For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.

Example:

       2
      / \
     3   9
    / \   \
   4   8   2
  /       /
 4       6
 
If you see in the above-depicted Binary Tree, we see that there are a total of two paths, 
starting from the root and ending at the leaves which sum up to a value of K = 13.

The paths are:
a. 2 3 4 4
b. 2 3 8

One thing to note here is, there is another path in the right sub-tree in reference to the root, which sums up to 13 but since it doesn't end at the leaf, we discard it.
The path is: 2 9 2(not a leaf)

Input Format:
The first line of input will contain the node data, all separated by a single space.
Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains an integer value K.

Output Format:
Lines equal to the total number of paths will be printed. 
All the node data in every path will be printed in a linear fashion taken in the order they appear from top to down bottom in the tree. A single space will separate them all.

Constriants:
1 <= N <= 10^5
0 <= K <= 10^8
Where N is the total number of nodes in the binary tree.
Time Limit: 1 second

Sample Input 1:
2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
13

Sample Output 1:
2 3 4 4 
2 3 8

Sample Input 2:
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13

Sample Output 2:
5 6 2
5 7 1
*/

#include<vector>
void helper(BinaryTreeNode<int>* root, int k, vector<int> &output){
    if(root == NULL){
        return;
    }
    else if(root -> left == NULL && root -> right == NULL){
		if((k - root -> data) == 0){
            output.push_back(root -> data);
            for(int i=0; i<output.size(); i++){
                cout<<output.at(i)<<" ";
            }
            cout<<"\n";
            output.pop_back();
            return;
        }
        else{
            return;
        }
    }
    else if(k - root -> data < 0){
        return;
    }
    else{
        //two calls, after which we pop from vector
        k = k - root->data;
        output.push_back(root -> data);
        helper(root-> left, k, output);
        helper(root-> right, k, output);
        output.pop_back();
        return;
    }
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> v;
    helper(root, k, v);
    return;
}
