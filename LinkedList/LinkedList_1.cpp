#include <bits/stdc++.h>
using namespace std;

// A linked list is a linear data structure in which elements (called nodes) are stored in separate memory locations and connected using pointers.
// size is not defined and elements are not in contigounous memory location. Linked List = Dynamic size + Non-contiguous memory + Pointers connecting nodes.
// Never unnecessarily modify/tamper with the head. Instead, use a temporary pointer for traversal.
// Given a linked list usually means you are given its head.


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


void Traversal(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


int lengthOfLL(Node* head) {
    int len = 0;
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        len++;
        temp = temp->next;
    }
    return len;
}


int checkIfPresent(Node* head, int val) {
    Node* temp = head;
    while(temp) {
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}


Node* removesHead(Node* head) {
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;        // or free(temp)
    return head;
}


Node* removesTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}


Node* removesPosition(Node* head, int pos) {
    if(head == NULL) return head;
    if(pos == 0) {            // remove head
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        if(cnt == pos) {
            prev->next = prev->next->next;        // or prev->next = temp->next
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}


Node* removesElement(Node* head, int el) {
    if(head == NULL) return head;
    if(head->data == el) {            // remove head
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        if(temp->data == el) {
            prev->next = prev->next->next;        // or prev->next = temp->next
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}



int main() {
    vector<int> arr = {12,33,44,15,58,87,89,23};
    Node* head = convertArr2LL(arr);
    // cout << endl << lengthOfLL(head);
    // cout << checkIfPresent(head,33);

    // cout << removesHead(head)->data;
    // head = removesTail(head);
    // head = removesPosition(head,3);
    head = removesElement(head,87);
    Traversal(head);
}




