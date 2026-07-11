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


// Traversals:
// two main methodologies used to navigate a tree
// Depth First Search (DFS): Explores one branch completely before moving to the next branch.
//         a. Pre-order: Root -> Left Subtree -> Right Subtree, The root is visited Pre (Before).
//         b. In-order: Left Subtree -> Root -> Right Subtree, The root is visited In (In-between).
//         c. Post-order: Left Subtree -> Right Subtree -> Root, The root is visited Post (After).
// Breadth First Search (BFS): Visits nodes level by level from left to right.
//         Start at the root (Level 0), read it, then move down to print all nodes across the next layer (Level 1) from left to right, repeating this for each subsequent horizontal layer


// Pre-order Traversal
// TC: O(n)
// SC: O(h), where h is the height of the tree.
// Worst Case: O(n) (skewed tree)
// Best/Average: O(log n) (balanced tree)
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

// Level-order Traversal
// TC: O(n) and SC: O(n)
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;

        for(int i=0; i<size; i++) {
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);

            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}


// Iterative Pre-Order
// TC: O(n) and SC: O(n)
vector<int> iterativePreOrder(Node* root) {
    vector<int> preorder;
    if(root == NULL) return preorder;

    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* curr = st.top();
        st.pop();
        preorder.push_back(curr->data);

        // push right first so left is processed first
        if(curr->right != NULL) st.push(curr->right);
        if(curr->left != NULL) st.push(curr->left); 
    }
    return preorder;
} 

// Iterative In-order
vector<int> iterativeInOrder(Node* root) {
    vector<int> inorder;
    stack<Node*> st;
    Node* curr = root;

    while(curr != NULL || !st.empty()) {
        if(curr != NULL) {
            st.push(curr);
            curr = curr->left;          // keep moving left
        }
        else {
            curr = st.top();
            st.pop();
            inorder.push_back(curr->data); // Process Root
            curr = curr->right;             // turn right
        }
    }
    return inorder;
}

// Iterative Post-order
vector<int> postorderTwoStacks(Node* root) {
    vector<int> postorder;
    if (root == NULL) return postorder;
    stack<Node*> st1, st2;
    st1.push(root);
    
    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);
        
        if (curr->left != NULL) st1.push(curr->left);
        if (curr->right != NULL) st1.push(curr->right);
    }
    while (!st2.empty()) {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}

vector<int> postorderOneStack(Node* root) {
    vector<int> postorder;
    if (root == NULL) return postorder;

    stack<Node*> st;
    Node* curr = root;
    Node* lastVisited = NULL;

    while (curr != NULL || !st.empty()) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;          // keep moving left
        }
        else {
            Node* temp = st.top()->right;

            // If right child doesn't exist or is already visited
            if (temp == NULL || temp == lastVisited) {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                lastVisited = temp;
            }
            else {
                curr = temp;            // move to right subtree
            }
        }
    }
    return postorder;
}


// Pre In Post Order Traversal in one Traversal
void preInPostTraversal(Node* root) {
    if (root == NULL) return;

    vector<int> pre, in, post;

    // Stack to store pairs of (Node*, State)
    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        Node* node = it.first;
        int state = it.second;

        // Condition 1: Preorder Phase
        if (state == 1) {
            pre.push_back(node->data); // Using .data here
            st.top().second++; 

            if (node->left != NULL) {
                st.push({node->left, 1});
            }
        }
        // Condition 2: Inorder Phase
        else if (state == 2) {
            in.push_back(node->data); // Using .data here
            st.top().second++; 

            if (node->right != NULL) {
                st.push({node->right, 1});
            }
        }
        // Condition 3: Postorder Phase
        else {
            post.push_back(node->data); // Using .data here
            st.pop(); 
        }
    }
}


int maxDepth(Node* root) {
    // TC: O(n) and SC: O(n)_worst_case_skewed_tree
    // Base Case: If the node is NULL, its height is 0
    if (root == NULL) {
        return 0;
    }

    // Recursively find the height of the left and right subtrees
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    // The height of the current node is 1 + the maximum of its children's heights
    return 1 + max(leftHeight, rightHeight);
    }


// Brute (TC: O(n^2))
bool check_BalancedBinaryTree(Node* root) {
    // for every node, height(left) - height(right) <= 1

    if(root == NULL) return true;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    if(abs(lh - rh) > 1) return false;

    bool left = check_BalancedBinaryTree(root->left);
    bool right = check_BalancedBinaryTree(root->right);

    if(!left || !right) return false;
    return true;
}
// Optimized (TC: O(n) and SC: O(h)/O(n)_worst)
int isBalanced(Node* root) {
    // Returns height if balanced, else -1
    if(root == NULL) return 0;

    int lh = isBalanced(root->left);
    if(lh == -1) return -1;

    int rh = isBalanced(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}
bool isBalancedBinaryTree(Node* root) {
    return isBalanced(root) != -1;
}





    
int main() {
    // Creating a Tree in the main Function
    // 1. Create the top-most root node
    Node* root = new Node(1);
    // 2. Assign and link the left child of the root
    root->left = new Node(2);
    // 3. Assign and link the right child of the root
    root->right = new Node(3);
    // 4. Further expansion (linking a child deeper in the hierarchy)
    root->left->right = new Node(5);
}




