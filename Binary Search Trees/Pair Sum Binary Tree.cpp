/*
Pair Sum Binary Tree
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.

Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. 
Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

The following line of input contains an integer, that denotes the value of S.

Output Format :
Print each pair in a new line, as described in the task. 

Constraints:
Time Limit: 1 second

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15

Sample Output 1:
5 10
6 9
*/

/*
    Time complexity: O(N)
    Space complexity: O(N)

    where N is the number of nodes in the input tree
*/

#include<vector>
#include<algorithm>
void create(BinaryTreeNode<int> *root, vector<int>& output){
    if(root == NULL){
        return;
    }
	output.push_back(root -> data);
    create(root->left, output);
    create(root->right, output);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int> v;
    create(root, v);
    sort(v.begin(), v.end());
	for(int i=0, j=v.size()-1; i<j;){
        int result = v[i] + v[j];
        if(result < sum){
            i++;
        }
        else if(result > sum){
            j--;
        }
        else{
            cout<<v[i]<<" "<<v[j]<<"\n";
            i++, j--;
        }
    }
}
