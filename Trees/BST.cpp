#include<bits/stdc++.h>
using namespace std;


// left->data < root->data < right->data, if duplicates are not allowed
// left->data <= root->data < right->data, if duplicates are allowed or we take a <node*,freq> data type at nodes
// left subtree and right subtree should also be a BST
// Height of BST: log2(n) in mostly cases
// for BST, inorder will always be in sorted form

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


void inorder(Node* root, int k, int &ans, int &count) {
    if(root == NULL || count >= k) return;
    inorder(root->left, k, ans, count);
    if(count >= k) return;
    count++;
    if(count == k) {
        ans = root->data;
        return;
    }
    inorder(root->right, k , ans, count);
}
int kthSmallest(Node* root, int k) {
    int ans = -1;
    int count = 0;
    inorder(root, k, ans, count);
    return ans;
}


int countNodes(Node* root) {
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
void inorder(Node* root, int k, int &ans, int &count) {
    if(root == NULL || count >= k) return;
    inorder(root->left, k, ans, count);
    if(count >= k) return;
    count++;
    if(count == k) {
        ans = root->data;
        return;
    }
    inorder(root->right, k , ans, count);
}
int kthLargest(Node* root, int k) {            // kth largest = (n - k + 1) smallest
    int n = countNodes(root);
    if(k > n || k <= 0) return -1;
    int count = 0, ans = -1;
    inorder(root, n - k + 1, ans, count);
    return ans;
}


void reverseInorder(Node* root, int k, int &count, int &ans) {
    if(root == NULL || count >= k) return;
    reverseInorder(root->right, k, count, ans);
    if(count >= k) return;
    count++;
    if(count == k) {
        ans = root->data;
        return;
    }
    reverseInorder(root->left, k, count, ans);
}
int kthLargest(Node* root, int k) {
    int count = 0, ans = -1;
    reverseInorder(root, k, count, ans);
    return ans;
}


bool solve(Node* root, long long mini, long long maxi) {
    if(root == NULL) return true;
    if(root->data <= mini || root->data >= maxi) return false;
    return solve(root->left, mini, root->data) &&
        solve(root->right, root->data, maxi);
}
bool isBST(Node* root) {
    return solve(root, LLONG_MIN, LLONG_MAX);
}


Node* LCA(Node* root, Node* p, Node* q) {
    // recursive
    // if(p->data < root->data && q->data < root->data) return LCA(root->left, p, q);
    // else if(p->data > root->data && q->data > root->data) return LCA(root->right, p, q);
    // return root;

    // iterative
    while(root) {
        if(p->data < root->data && q->data < root->data) root = root->left;
        else if(p->data > root->data && q->data > root->data) root = root->right;
        else return root;
    }
    return NULL;
}


Node* build(vector<int> &preorder, int &i, int bound) {
    if(i == preorder.size() || preorder[i] > bound) return NULL;
    Node* newNode = new Node(preorder[i++]);
    newNode->left = build(preorder, i, newNode->data);
    newNode->right = build(preorder, i, bound);
    return newNode;
}
Node* constructBST(vector<int> preorder) {         // construct BST from given preorder
    // TC: O(nlogn + n) and SC: O(n)
    // sort that preorder and store in different vector as inorder
    // then construct BT with both of them, resultant BT is the required BST

    // TC: O(n) and SC: O(1)
    int i = 0;
    return build(preorder, i, INT_MAX);
}


Node* inorderSuccessor(Node* root, Node* p) {
    Node* successor = NULL;
    while(root != NULL) {
        if(p->data >= root->data) root = root->right;
        else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}


Node* inorderPredecessor(Node* root, Node* p) {
    Node* predecessor = NULL;
    while(root != NULL) {
        if(p->data <= root->data) root = root->left;
        else {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}


class BSTIterator {
    private: stack<Node*> st;
    public:
        BSTIterator(Node* root) {
            pushAll(root);
        }

        bool hasNext() {
            return !st.empty();
        }

        int next() {
            Node* temp = st.top();
            st.pop();
            pushAll(temp->right);
            return temp->data;
        }

    private:
        void pushAll(Node* node) {
            for(; node != NULL; st.push(node), node = node->left);
        }
};


bool twoSum(Node* root, int k) {
    // TC: O(n) + O(n) and SC: O(n)
    // convert the BST into a sorted vector using inorder traversal, then use Binary Search to find the sum.

    // TC: O(n) and SC: 2 * O(h)
    // see classes below
}
class BSTIterator {
    stack<Node*> st;
    bool reverse = true;

public:
    BSTIterator(Node* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        Node* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->data;
    }

private:
    void pushAll(Node* node) {
        for(; node != NULL;) {
            st.push(node);
            if(reverse == true) node = node->right;
            else node = node->left;
        }
    }
};
class solution {
public:
    bool findTarget(Node* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);     // next
        BSTIterator r(root, true);       // before

        int i = l.next();
        int j = r.next();
        while(i < j) {
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};




int main() {

}




