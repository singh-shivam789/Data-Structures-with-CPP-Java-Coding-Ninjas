/*
Level wise linkedlist
Given a binary tree, write code to create a separate linked list for each level. 
You need to return the array which contains head of each level linked list.

Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. 
Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :
Each level linked list is printed in new line (elements are separated by space).

Constraints:
Time Limit: 1 second

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:
5 
6 10 
2 3 
9
*/

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> v;
    queue<BinaryTreeNode<int>*> q;
    if(root == NULL){
        return v;
    }
    else if(root -> left == NULL && root -> right == NULL){
        Node<int>* newNode = new Node<int>(root -> data);
        v.push_back(newNode);
        return v;
    }
    else{
        q.push(root);
        q.push(NULL);
        Node<int>* head = NULL;
        Node<int>* tail = NULL;
        bool hasChildren = false;
        while(q.size() != 0){
            BinaryTreeNode<int>* front = q.front();
            q.pop();
            if(front == NULL){
                if(!q.empty()){
                    v.push_back(head);
                    head = NULL;
                    tail = NULL;
                    q.push(NULL);
                    hasChildren = false;
                }
                else{
                    if(hasChildren == false){
                        v.push_back(head);
                        return v;
                    }
                }
            }
            else{
                Node<int>* newNode = new Node<int>(front -> data);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                }
                else{
                    tail -> next = newNode;
                    tail = newNode;
                }

                if(front -> left != NULL){
                    q.push(front -> left);
                    hasChildren = true;
                }
                if(front -> right != NULL){
                    q.push(front -> right);
                    hasChildren = true;
                }
            }
        }
        return v;
    }
}
