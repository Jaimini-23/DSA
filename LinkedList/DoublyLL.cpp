#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
    int data;        // stores the value
    Node* next;      // pointer to another node
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};


Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}


void Traversal(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


Node* deleteHead(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}


Node* deleteTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}


Node* deletePosition(Node* head, int k) {
    if(head == NULL) return NULL;
    Node* kNode = head;
    int cnt = 0;

    // Find kth node
    while (kNode != NULL) {
        cnt++;
        if (cnt == k)
            break;
        kNode = kNode->next;
    }

    Node* prev = kNode->back;
    Node* front = kNode->next;

    // Only one node
    if (prev == NULL && front == NULL) {
        delete kNode;
        return NULL;
    }

    // Kth node is head
    else if (prev == NULL) {
        return deleteHead(head);
    }

    // Kth node is tail
    else if (front == NULL) {
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;

    delete kNode;
    return head;
}



int main() {
    vector<int> arr = {12,33,44,15,58,87,89,23};
    Node* head = convertArr2DLL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    head = deletePosition(head,4);
    Traversal(head);
    return 0;
}














