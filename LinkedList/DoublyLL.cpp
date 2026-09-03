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


void deleteElement(Node* temp) {         // cannot pass head
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL) {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}


Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val,head,nullptr);
    head->back = newHead;
    return newHead;
}


Node* insertBeforeTail(Node* head, int val) {
    if(head->next == NULL) return insertBeforeHead(head,val);
    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val,tail,prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}


Node* insertBeforePosition(Node* head, int val, int pos) {
    if(pos == 1) {
        return insertBeforeHead(head,val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        if(cnt == pos) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);

    prev->next = newNode;
    temp->back = newNode;
    return head;
}


Node* insertBeforeElement(Node* node, int val) {
    Node* prev = node->back;
    Node* newNode = new Node(val,node,prev);
    prev->next = newNode;
    node->back = newNode;
}


Node* reverseLL(Node* head) {
    // TC: O(n) and SC: O(1)
    if(head == NULL || head->next == NULL) return head;
    Node* current = head;
    Node* prev = NULL;
    while(current != NULL) {
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }
    return prev->back;
}


Node* deleteAllOccurrences(Node* head, int k) {
    // TC: O(n) and SC: O(1)
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == k) {
            if(temp == head) {
                head = head->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->back; 
            if(nextNode != NULL) nextNode->back = prevNode;
            if(prevNode != NULL) prevNode->next = nextNode;
            delete temp;
            temp = nextNode;
        }
        else {
            temp = temp->next;
        }
    }
    return head;
}




int main() {
    vector<int> arr = {12,33,44,15,58,87,89,23};
    Node* head = convertArr2DLL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deletePosition(head,4);
    // deleteElement(head->next->next);
    // Traversal(head);

    // head = insertBeforeHead(head,10);
    // head = insertBeforeTail(head,10);
    //head = insertBeforePosition(head,10,5);
    // insertBeforeElement(head->next->next,10);
    // Traversal(head);

    head = reverseLL(head);
    Traversal(head);
    return 0;
}




