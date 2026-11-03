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




int main() {

}