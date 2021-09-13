/*
Replace with depth
You are given a generic tree. 
You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.

Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. 
The data of the nodes of the tree is separated by space.  

Output format:
The updated tree is printed level wise. Each level is printed in a new line. Please refer to sample output 1 for more details. 

Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1:
0 
1 1 1 
2 2
*/

void helper(TreeNode<int>* root, int currentHeight){
    if(root == NULL){
        return;
    }
    if(root -> children.size() == 0){
        root -> data = currentHeight;
        return;
    }
    else{
        root -> data = currentHeight;
        for(int i=0; i<root -> children.size(); i++){
            helper(root -> children[i], currentHeight + 1);
        }
        
        return;
    }
}
void replaceWithDepthValue(TreeNode<int>* root) {
    helper(root, 0);
}
