/*
BST Class

Implement the BST class which includes following functions -
1. search

Given an element, find if that is present in BST or not. Return true or false.
2. insert -

Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
3. delete -

Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -

Print the BST in ithe following format -

For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.

There is no space in between.
You need to print all nodes in the recursive format in different lines.
*/

class BST {
    BinaryTreeNode<int>* root;

   public:
    BST() { 
        root = NULL; 
    }

    ~BST() { 
        delete root; 
    }

   private:
    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* node, int data) {
        if (node == NULL) {
            return NULL;
        }

        if (data > node->data) {
            node->right = remove(node->right, data);
            return node;
        } else if (data < node->data) {
            node->left = remove(node->left, data);
            return node;
        } else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } else if (node->left == NULL) {
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            } else {
                BinaryTreeNode<int>* minNode = node->right;

                while (minNode->left != NULL) {
                    minNode = minNode->left;
                }

                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = remove(node->right, rightMin);
                return node;
            }
        }
    }

    void print(BinaryTreeNode<int>* root) {
        if (root == NULL) {
            return;
        }

        cout << root->data << ":";

        if (root->left != NULL) {
            cout << "L:" << root->left->data << ",";
        }

        if (root->right != NULL) {
            cout << "R:" << root->right->data;
        }

        cout << endl;

        print(root->left);
        print(root->right);
    }

   public:
    void remove(int data) { 
        root = remove(root, data); 
    }

    void print() { 
        print(root); 
    }

   private:
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int data) {
        if (node == NULL) {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }

        return node;
    }

   public:
    void insert(int data) { 
        this->root = insert(this->root, data); 
    }

   private:
    bool search(BinaryTreeNode<int>* node, int data) {
        if (node == NULL) {
            return false;
        }

        if (node->data == data) {
            return true;
        } else if (data < node->data) {
            return search(node->left, data);
        } 

        return search(node->right, data);
        
    }

   public:
    bool search(int data) { 
        return search(root, data); 
    }
};
