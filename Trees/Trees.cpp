#include<bits/stdc++.h>
using namespace std;

// Linear vs. Hierarchical: Arrays, stacks, queues, and linked lists are linear data structures.
//      Trees, by contrast, are hierarchical data structures (like the folder structure in your computer)
// Binary Tree: A tree data structure where each node can have at max 2 children (0, 1, or 2 children)

// Key Terminology
// Root: The top-most node or starting point of the tree
// Children: The nodes located directly beneath a parent node
// Leaf Node: A node that does not have any children
// Sub Tree: A smaller tree structure formed by a chosen node and all the nodes beneath it
// Ancestors: The lineage of parent nodes going all the way up to the root (parent, grandparent, etc.)

// Types of Binary Trees
// 1. Full Binary Tree: Every single node must have either 0 or 2 children. A node cannot have exactly 1 child
// 2. Complete Binary Tree: All levels of the tree must be completely filled, with the only exception being the last level.
//      For the last level, all nodes must be pushed as far left as possible
// 3. Perfect Binary Tree: All leaf nodes must be at the exact same level
// 4. Balanced Binary Tree: The total height of the tree can be at a maximum of $O(\log N)$, where $N$ represents the number of nodes
//      Keeping a tree balanced prevents it from getting too deep, ensuring search operations remain highly efficient
// 5. Degenerate (Skewed) Tree: Every single node has exactly one child. This type of tree forms a straight line and essentially behaves like a linear linked list


// Conceptual Memory Representation:
// Node Structure: In C++, a binary tree node is represented in memory as an object containing three components
//      An integer data type to hold the value of the node.
//      A left pointer directed toward the left child node.
//      A right pointer directed toward the right child node.
// Null Pointers: For leaf nodes or any node missing a left/right child, their respective pointer points directly to NULL


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

// Initialization: When a new node is initialized using the constructor, it assigns the passed value to data, while defaulting both the left and right pointers to NULL

// Creating a Tree in the main Function
int main() {
    // 1. Create the top-most root node
    Node* root = new Node(1);
    // 2. Assign and link the left child of the root
    root->left = new Node(2);
    // 3. Assign and link the right child of the root
    root->right = new Node(3);
    // 4. Further expansion (linking a child deeper in the hierarchy)
    root->left->right = new Node(5);
}


// Traversals:
// two main methodologies used to navigate a tree
// 1. Depth First Search (DFS): Navigates deep into the subtrees first.
//         a. Pre-order: Root -> Left Subtree -> Right Subtree, The root is visited Pre (Before).
//         b. In-order: Left Subtree -> Root -> Right Subtree, The root is visited In (In-between).
//         c. Post-order: Left Subtree -> Right Subtree -> Root, The root is visited Post (After).
// 2. Breadth First Search (BFS): Navigates broadly across the structure level by level.
//         Start at the root (Level 0), read it, then move down to print all nodes across the next layer (Level 1) from left to right, repeating this for each subsequent horizontal layer


// Pre-order Traversal
// TC: O(n) and SC: O(n) where n is total number of nodes in the binary tree.
void preorder(Node* node) { 
    if(node == NULL) return;         // Base Condition

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// In-order Traversal
void inorder(Node* node) {
    if(node == NULL) return;         // Base Condition
    
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// Post-order Traversal
void postorder(Node* node) {
    if(node == NULL) return;          // Base Condition

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

