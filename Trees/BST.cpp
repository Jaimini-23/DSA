#include<bits/stdc++.h>
using namespace std;


// left->data < root->data < right->data, if duplicates are not allowed
// left->data <= root->data < right->data, if duplicates are allowed or we take a <node*,freq> data type at nodes
// left subtree and right subtree should also be a BST
// Height of BST: log2(n) in mostly cases

// The Code Structure (Defining a Node)
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node with a value
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node* searchNode(Node* root, int x) {
    // TC: height of BST O(log2(n))
    while(root != NULL || root->data != x) {
        root = x < root->data ? root->left : root->right;
    }
    return root;
}


int ceil(Node* root, int x) {        // val >= x
    int ceil = -1;
    while(root) {
        if(root->data == x) return root->data;      // or return x
        if(x > root->data) root = root->right;
        else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}


int floor(Node* root, int x) {        // val <= x
    int floor = -1;
    while(root) {
        if(root->data == x) return root->data;      // or return x
        if(x > root->data) {
            floor = root->data;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return floor;
}


Node* insertAtLeaf(Node* root, int x) {
    if(root == NULL) return new Node(x);
    Node* curr = root;
    while(true) {
        if(x >= curr->data) {
            if(curr->right != NULL) curr = curr->right;
            else {
                curr->right = new Node(x);
                break;
            }
        }
        else {
            if(curr->left != NULL) curr = curr->left;
            else {
                curr->left = new Node(x);
                break;
            }
        }
    }
    return root;
}


Node* deleteNode(Node* root, int key) {          // Recursive Approach
    if(root == NULL) return NULL;
    if(key < root->data) root->left = deleteNode(root->left, key);
    else if(key > root->data) root->right = deleteNode(root->right, key);
    else {
        // Case 1: No left child
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: No right child
        if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* successor = root->right;
        while(successor->left != NULL) successor = successor->left;
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}


Node* findLastRight(Node* root) {
    if(root->right == NULL) return root;
    return findLastRight(root->right);
}
Node* helper(Node* root) {
    // it attaches the right subtree to the rightmost node of the left subtree.
    if(root->left == NULL) return root->right;
    else if(root->right == NULL) return root->left;
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;

    return root->left;
}
Node* deleteNode(Node* root, int key) {            // Iterative Approach
    if(root == NULL) return NULL;
    if(root->data == key) return helper(root);
    Node* node = root;
    while(root != NULL) {
        if(root->data > key) {
            if(root->left != NULL && root->left->data == key) {
                root->left = helper(root->left);
                break;
            }
            else root = root->left;
        }
        else {
            if(root->right != NULL && root->right->data == key) {
                root->right = helper(root->right);
                break;
            }
            else root = root->right;
        }
    }
    return node;
}




int main() {

}