#include <bits/stdc++.h>
using namespace std;

// A linked list is a linear data structure in which elements (called nodes) are stored in separate memory locations and connected using pointers.
// size is not defined and elements are not in contigounous memory location. Linked List = Dynamic size + Non-contiguous memory + Pointers connecting nodes.

class Node {
    public:
    int data;        // stores the value
    Node* next;      // pointer to another node

    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}





int main() {
    vector<int> arr = {12,3,4,5};
    // Node *y = new Node(arr[0],nullptr);
    Node* head = convertArr2LL(arr);
    cout << head->data;
    //cout << y -> next;
}











