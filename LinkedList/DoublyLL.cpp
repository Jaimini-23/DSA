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


Node* findTail(Node* head) {
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}
vector<pair<int,int>> pairsOfGivenSum(Node* head, int k) {        // LinkedList is sorted
    // TC: O(2n) and SC: O(1)_in solve but some space to return the ans
    vector<pair<int,int>> ans;
    if(head == NULL) return ans;
    Node* left = head;
    Node* right = findTail(head);
    while(left != right && left->back != right) {
        if(left->data + right->data == k) {
            ans.push_back({left->data,right->data});
            left = left->next;
            right = right->back;
        }
        else if(left->data + right->data < k) left = left->next;
        else right = right->back;
    }
    return ans;
}


Node* removeDuplicates(Node* head) {              // for sorted DLL 
    // TC: O(n)_includes both loops and SC: O(1)
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    while(temp != NULL && temp->next != NULL) {
        Node* newNode = temp->next;
        while(newNode != NULL && newNode->data == temp->data) {
            Node* duplicate = newNode;
            newNode = newNode->next;
            delete duplicate;
        }
        temp->next = newNode;
        if(newNode != NULL) newNode->back = temp;
        temp = temp->next;
    }
    return head;
}


Node* merge(Node* t1, Node* t2) {
    // Node* dummyNode = new Node(-1);
    // Node* temp = dummyNode;
    // while(t1 != NULL && t2 != NULL) {
    //     if(t1->data < t2->data) {
    //         temp->child = t1;
    //         temp = t1;
    //         t1 = t1->child;
    //     }
    //     else {
    //         temp->child = t2;
    //         temp = t2;
    //         t2 = t2->child;
    //     }
    //     temp->next = nullptr;
    // }

    // if(t1) temp->child = t1;
    // else temp->child = t2;
    // if(dummyNode->child) dummyNode->child->next = nullptr;
    // return dummyNode->child;
}
Node* flattening(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* mergeHead = flattening(head->next);
    head = merge(head,mergeHead);
    return head;
}


void insertInBetween(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        Node* nextElement = temp->next;
        Node* copy = new Node(temp->data);
        copy->next = nextElement;
        temp->next = copy;

        temp = nextElement;
    }
}
void connectRandomPointers(Node* head) {
    // Node* temp = head;
    // while(temp != NULL) {
    //     Node* copyNode = temp->next;
    //     if(temp->random) copyNode->random = temp->random->next;
    //     else copyNode->random = nullptr;
    //     temp = temp->next->next;
    // }
}
Node* getDeepCopyList(Node* head) {
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while(temp != NULL) {
        // creating new list
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}
Node* cloneRandomPointerLL(Node* head) {
    // TC: O(2n) and SC: O(n)_map + O(n)_clone
    // Node* temp = head;
    // map<Node*,Node*> mp;
    // while(temp != NULL) {
    //     Node* newNode = new Node(temp->data);
    //     mp[temp] = newNode;
    //     temp = temp->next;
    // }
    // temp = head;
    // while(temp != NULL) {
    //     Node* copyNode = mp[temp];
    //     copyNode->next = mp[temp->next];
    //     copyNode->random = mp[temp->random];
    //     temp = temp->next;
    // }
    // return mp[head];

    // TC: O(3n) and SC: O(n)_clone
    insertInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}




int main() {
    vector<int> arr = {12,33,10,44,15,58,10,87,89,23,31};
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

    // head = reverseLL(head);
    // head = deleteAllOccurrences(head,10);
    // Traversal(head);

    // vector<pair<int,int>> result = pairsOfGivenSum(head,54);
    // for(auto it : result) {
    //     cout << it.first << " " << it.second << endl;
    // }
    head = removeDuplicates(head);
    Traversal(head);
    return 0;
}




