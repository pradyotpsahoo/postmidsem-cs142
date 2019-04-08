#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node * left;
    Node * right;
    Node * parent;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
        parent = NULL;
    }  
};

class BST{
public:
    Node * root;
    BST(){
        root = NULL;
    }
    void insertHelper(int value){
        insert(root, value);
    }
    void insert(Node *curr, int value){
        // If root is NULL, then create a node and make it root. 
        if (root == NULL) root = new Node(value);
        // Else Decide to move left or right. 
        else if (value < curr->data)  {
            // if left is already NULL, create a new node and link it. 
            if (curr->left == NULL) {
                curr->left = new Node(value);
                curr->left->parent = curr;
            }
            // Move left and call insert there. 
            else insert(curr->left, value);
        }
        else {
            // if right is already NULL, create a new node and link it. 
            if (curr->right == NULL) {
                curr->right = new Node(value);
                curr->right->parent = curr;
            }
            // Move right and call insert there. 
            else insert(curr->right, value);
        }
    }
    void displayHelper(){
        display(root);
    }
    void display(Node * curr){
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
        // IN order print.
        // Print left. 
        display(curr->left);
        // Print myself.
        cout << curr->data << ", ";
        // Print right.
        display(curr->right);
    }
    Node * searchHelper(int value){
        return search(root, value);
    }
    Node * search(Node * curr, int value){
        // Are you the value? or Are you NULL?  if yes return curr
        if(curr == NULL || curr->data == value ) return curr;
        // else you search in right or left. 
        // Left
        else if(value < curr->data) return search(curr->left, value);
        // Right
        else  return search(curr->right, value);
    }
    Node * find_min(Node * curr){
        if (curr->left != NULL)
            return find_min(curr->left);
        return curr;    
    }

    int count(Node * curr){
        if (curr==NULL) return 0;
        return 1 + count(curr->left) + count(curr->right);
    }
    int max(int a, int b){
        if (a>b) return a;
        else return b;
    }
    int height(Node * curr){
        if (curr==NULL) return 0;
        return 1 + max(height(curr->left),height(curr->right));
    }

};

int main(){
    BST bst1;
    bst1.insertHelper(4);
    bst1.insertHelper(2);
    bst1.insertHelper(3);
    bst1.insertHelper(1);
    bst1.insertHelper(6);
    bst1.insertHelper(5);
    bst1.insertHelper(7);
    bst1.insertHelper(8);
    bst1.displayHelper();
    if(bst1.searchHelper(3) != NULL){
        cout << endl << bst1.searchHelper(3)->data << endl;
    }
    
    cout << "Number of nodes - " << bst1.count(bst1.root) << endl;
    cout << "Height of tree - " << bst1.height(bst1.root->right) << endl;

 
}
