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
        // cnt++       for 1 based indexing
        if(cnt == pos) {
            prev->next = prev->next->next;        // or prev->next = temp->next
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;          // for zero based indexing
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


Node* insertHead(Node* head, int val) {
    return new Node(val,head);
} 


Node* insertTail(Node* head, int val) {
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new Node(val);       // temp->next = new Node(val,temp->next);
    return head;
} 


Node* insertPosition(Node* head, int pos, int el) {
    if(head == NULL) {
        if(pos == 1) return new Node(el);
        else return head;
    }
    if(pos == 1) {
        return new Node(el,head);
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        if(cnt == pos - 1) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}


Node* insertBeforeValue(Node* head, int val, int el) {
    if(head == NULL) {
        return NULL;
    }
    if(head->data == val) {
        return new Node(el,head);
    }

    Node* temp = head;
    while(temp != NULL && temp->next != NULL) {
        if(temp->next->data == val) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}


Node* reverseLL(Node* head) {
    // TC: O(2n) and SC: O(n)
    // stack<int> st;
    // Node* temp = head;
    // while(temp != NULL) {
    //     st.push(temp->data);
    //     temp = temp->next;
    // }

    // temp = head;
    // while(temp != NULL) {
    //     temp->data = st.top();
    //     st.pop();
    //     temp = temp->next;
    // }
    // return head;

    // Optimal
    // TC: O(n) and SC: O(1)
    Node* current = head;
    Node* prev = NULL;
    while(current != NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


Node* reverseByRecursion(Node* head) {
    // Tc: O(n) and SC: O(n)_recursive_stack_spaces
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseByRecursion(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}


// Concept of Dummy Node
Node* addTwoNumbers(Node* head1, Node* head2) {
    // TC: O(max(n,m)) and SC: O(max(n,m))
    Node* dummyHead = new Node(-1);
    Node* t1 = head1;
    Node* t2 = head2;
    int carry = 0;
    Node* current = dummyHead;
    while(t1 != NULL || t2 != NULL) {
        int sum = carry;
        if(t1) sum += t1->data;
        if(t2) sum += t2->data;

        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        current->next = newNode;
        current = current->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }

    if(carry) {
        Node* newNode = new Node(carry);
        current->next = newNode;
    }
    return dummyHead->next;
}


vector<vector<int>> oddEvenLL(Node* head) {
    // TC: O(2n) and SC: O(n)
    vector<vector<int>> ans;
    Node* temp = head;
    vector<int> arrOdd;
    while(temp != NULL && temp->next != NULL) {       // because if temp->next is null then temp->next->next is undefined;
        arrOdd.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) {                 // if temp is the last element
        arrOdd.push_back(temp->data);
    }
    ans.push_back(arrOdd);

    // for even
    temp = head->next;
    vector<int> arrEven;
    while(temp != NULL && temp->next != NULL) {
        arrEven.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) {
        arrEven.push_back(temp->data);
    }
    ans.push_back(arrEven);
    return ans;
}


Node* oddEvenLL2(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even != NULL && even->next != NULL) {
        odd->next = odd->next->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;      // connecting odd tail to even head
    return head;
}


Node* sort012(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    // Dummy nodes
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    // Tail pointers
    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == 0) {
            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        } else if (temp->data == 1) {
            oneTail->next = temp;
            oneTail = oneTail->next;
        } else {
            twoTail->next = temp;
            twoTail = twoTail->next;
        }
        temp = temp->next;
    }

    // 1. Connect 0-tail to 1-list (or 2-list if 1-list is empty)
    zeroTail->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next;
    // 2. Connect 1-tail to 2-list
    oneTail->next = twoHead->next;
    // 3. Terminate 2-tail
    twoTail->next = NULL;
    // Save actual head before deleting dummy nodes
    Node* newHead = zeroHead->next;

    // Safely delete original dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}


Node* remove_KthNode_fromEnd(Node* head, int k) {
    // TC: O(n) and SC: O(1)
    Node* fast = head;
    for(int i=0; i<k; i++) fast = fast->next;
    if(fast == NULL) return head->next;
    Node* slow = head;
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}


bool isPalindrome(Node* head) {
    // Tc: O(2n) and SC: O(n)
    // if(head == NULL || head->next == NULL) return 1;
    // stack<int> st;
    // Node* temp = head;
    // while(temp != NULL) {
    //     st.push(temp->data);
    //     temp = temp->next;
    // }
    // temp = head;
    // while(temp != NULL) {
    //     if(temp->data != st.top()) return 0;
    //     temp = temp->next;
    //     st.pop();
    // }
    // return 1;

    // TC: O(2n) and SC: O(1)
    if(head == NULL || head->next == NULL) return true;
    Node* fast = head;
    Node* slow = head;
    while(fast->next != NULL && fast->next->next != NULL) {     // you will reach to end of first half in case of even elements or in middle of LL in case of odd elements
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != NULL) {
        if(first->data != second->data) {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}


int helper(Node* head) {
    Node* temp = head;
    if(temp == NULL) return 1;
    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}
Node* addOne(Node* head) {              // 159 + 1 = 160 or 9999 + 1 = 10000
    // TC: O(3n) and SC: O(1)
    // head = reverseLL(head);
    // Node* temp = head;
    // int carry = 1;
    // while(temp != NULL) {
    //     temp->data = temp->data + carry;
    //     if(temp->data < 10) {
    //         carry = 0;
    //         break;
    //     }
    //     else {
    //         temp->data = 0;
    //         carry = 1;
    //     }
    //     temp = temp->next;
    // }
    // if(carry) {
    //     Node* newNode = new Node(1);
    //     head = reverseLL(head);
    //     newNode->next = head;
    //     return newNode;
    // }
    // head = reverseLL(head);
    // return head;

    // TC: O(n) and SC: O(n)
    int carry = helper(head);       // to access the singly LL from back, we can use recursion(back tracking) instead reverse
    if(carry) {
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}


Node* intersectionNode(Node* head1, Node* head2) {
    // average
    // int len1 = lengthOfLL(head1);
    // int len2 = lengthOfLL(head2);
    // int diff = abs(len1 - len2);
    // Node* t1 = head1;
    // Node* t2 = head2;
    // if(len2 > len1) {
    //     for(int i=0; i<diff; i++) t2 = t2->next;
    // }
    // else {
    //     for(int i=0; i<diff; i++) t1 = t1->next;
    // }
    // while(t1 != t2 && t1 != NULL && t2 != NULL) {
    //     t1 = t1->next;
    //     t2 = t2->next;
    // }
    // return t1;

    // TC: O(n+m) and SC: O(1)
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1 != t2) {
        if(t1 == NULL) {
            t1 = head2;
        }
        else t1 = t1->next;
        if(t2 == NULL) {
            t2 = head1;
        }
        else t2 = t2->next;
        // these conditions are alligning the pointers on same vertical level
    }
    return t1;
}


Node* middleElement(Node* head) {
    // TC: O(n + n/2) and SC: O(1)
    // if(head == NULL || head->next == NULL) return head;
    // int cnt = 0;
    // Node* temp = head;
    // while(temp != NULL) {
    //     cnt++;
    //     temp = temp->next;
    // }
    // temp = head;
    // int middleNode = (cnt/2) + 1;
    // while(temp != NULL) {
    //     middleNode--;
    //     if(middleNode == 0) break;
    //     temp = temp->next;
    // }
    // return temp;

    // Tortoise and Hair 
    // TC: O(n/2) and SC: O(1)
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL) {     // for 2nd middle in even length
        fast = fast->next->next;                    // for 1st middle in even length, while(fast->next != NULL && fast->next->next != NULL)
        slow = slow->next;
    }
    return slow;
}


bool detectLoop(Node* head) {
    // TC: O(n * 2*logn) and SC: O(n)
    // Node* temp = head;
    // map<Node*,int> mp;
    // while(temp != NULL) {
    //     if(mp.find(temp) != mp.end()) return true;
    //     mp[temp] = 1;
    //     temp = temp->next;
    // }
    // return false;

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) return true;
    }
    return false;
}


int length(Node* slow,Node* fast) {
    int cnt = 1;
    fast = fast->next;
    while(fast != slow) {
        fast = fast->next;
        cnt++;
    }
    return cnt;
}
int lengthOfLoop(Node* head) {
    // Hashing
    // Node* temp = head;
    // map<Node*,int> mp;
    // int timer = 1;
    // while(temp != NULL) {
    //     if(mp.find(temp) != mp.end()) {
    //         int value = mp[temp];
    //         return timer - value;
    //     }
    //     mp[temp] = timer;
    //     timer++;
    //     temp = temp->next;
    // }
    // return 0;

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) return length(slow,fast);
    }
    return 0;
}


Node* deleteMiddle(Node* head) {
    // TC: O(n + n/2) and SC: O(1)
    // if(head == NULL || head->next == NULL) return NULL;
    // int len = lengthOfLL(head);
    // int res = len / 2;
    // Node* temp = head;
    // while(temp != NULL) {
    //     res--;
    //     if(res == 0) {
    //         Node* middle = temp->next;
    //         temp->next = temp->next->next;
    //         delete middle;
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // return head;

    // TC: O(n/2) and SC: O(1)
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}


Node* loopNode(Node* head) {      // the node from that linked list loop starts
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}


Node* findKthNode(Node* temp, int k) {
    k -= 1;
    while(k > 0 && temp != NULL) {
        k--;
        temp = temp->next;
    }
    return temp;
}
Node* reverseNodes_inKGroups(Node* head, int k) {
    Node* temp = head;
    Node* prevNode = NULL;
    while(temp != NULL) {
        Node* KthNode = findKthNode(temp,k);
        if(KthNode == NULL) {
            if(prevNode) prevNode->next = temp;
            break;
        }

        Node* nextNode = KthNode->next;
        KthNode->next = NULL;
        Node* newHead = reverseLL(temp);
        if(temp == head) head = newHead;         // for first time
        else prevNode->next = newHead;

        prevNode = temp;
        temp = nextNode;
    }
    return head;
}


Node* rotate(Node* head, int k) {
    // TC: O(2n) and SC: O(1)
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    int len = 1;
    while(temp->next != NULL) {
        len++;
        temp = temp->next;
    }
    if(k % len == 0) return head;
    k = k % len;

    temp->next = head;
    Node* newLastNode = findKthNode(head,len - k);
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}


Node* mergeTwoSortedLL(Node* head1, Node* head2) {
    // TC: O(n + m) and SC: O(1)
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1 != NULL && t2 != NULL) {
        if(t1->data < t2->data) {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    if(t1) temp->next = t1;
    else temp->next = t2;
    return dummyNode->next;
}


Node* mergeKsortedLists(vector<Node*>& list) {
    // Brute (TC: O(n + nlogn + n) and SC: O(n))
    // vector<int> arr;
    // for(int i=0; i<list.size(); i++) {
    //     Node* temp = list[i];
    //     while(temp != NULL) {
    //         arr.push_back(temp->data);
    //         temp = temp->next;
    //     }
    // }
    // sort(arr.begin(),arr.end());
    // Node* head = convertArr2LL(arr);
    // return head;

    // Better (TC: ~O(n^3) ans SC: O(1))
    // if(lists.empty()) return NULL;
    // Node* head = list[0];
    // for(int i=1; i<list.size(); i++) {
    //     head = mergeTwoSortedLL(head, list[i]); 
    // }
    // return head;

    // Optimal (TC: ~O(nlogk) and SC: O(k))
    priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;      // min heap
    for(int i=0; i<list.size(); i++) {
        if(list[i]) {
            pq.push({list[i]->data,list[i]});
        }
    }
    
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        if(it.second->next) pq.push({it.second->next->data, it.second->next});
        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
}


Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    fast = fast->next;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node* sort(Node* head) {                  // Merge Sort
    // TC: O(nlogn) and SC: O(logn)_recursive Stacks
    if(head == NULL || head->next == NULL) return head;
    Node* middle = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = nullptr;

    leftHead = sort(leftHead);
    rightHead = sort(rightHead);
    return mergeTwoSortedLL(leftHead,rightHead);
}




int main() {
    vector<int> arr = {12,23,48,59,75,86,26,42,53,51,49};
    Node* head = convertArr2LL(arr);
    // cout << endl << lengthOfLL(head);
    // cout << checkIfPresent(head,33);

    // cout << removesHead(head)->data;
    // head = removesTail(head);
    // head = removesPosition(head,3);
    // head = removesElement(head,87);
    // Traversal(head);

    // head = insertHead(head,03);
    // head = insertTail(head,99);
    // head = insertPosition(head,1,45);
    // head = insertBeforeValue(head,44,29);
    // Traversal(head);
    
    // head = reverseLL(head);
    // head = reverseByRecursion(head);
    // vector<int> arr1 = {1,2,8};
    // vector<int> arr2 = {7,7,7};
    // Node* head1 = convertArr2LL(arr1);
    // Node* head2 = convertArr2LL(arr2);
    // head = addTwoNumbers(head1,head2);
    // Traversal(head);

    // vector<vector<int>> result = oddEvenLL(head);
    // for(auto it : result) {
    //     for(auto x : it) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    // head = oddEvenLL2(head);
    // head = sort012(head);
    // head = remove_KthNode_fromEnd(head,4);
    // cout << isPalindrome(head);
    // Traversal(head);

    // head = addOne(head);
    // Traversal(head);

    head = reverseNodes_inKGroups(head,3);
    Traversal(head);
    return 0;
}




