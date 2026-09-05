#include <bits/stdc++.h>
using namespace std;


class stackImp {
    private: 
    int arr[10];
    int topIndex;
    int size;

    public:
    stackImp() {
       topIndex = -1;
       size = 0; 
    }

    void push(int x) {
        if(topIndex == 9) {
            cout << "Stack Overflow";
            return;
        }
        topIndex++;
        arr[topIndex] = x;
        size++;
    }

    void pop() {
        if(topIndex == -1) {
            cout << "Stack Underflow";
            return;
        }
        topIndex--;
        size--;
    }

    int top() {
        if(topIndex == -1) {
            cout << "Stack is Empty";
            return -1;
        }
        return arr[topIndex];
    }

    int getSize() {
        return size;
    }
    bool empty() {
        return topIndex == -1;             // return size == 0;
    }
};


class queueImp {
    private:
    int arr[10];
    int frontIndex;
    int rearIndex;
    int size;

    public:
    queueImp() {
        frontIndex = -1;
        rearIndex = -1;
        size = 0;
    }

    // Insert at rear/back/end
    void push(int x) {
        if(size == 10) {
            cout << "Queue Overflow";
            return;
        }
        if(size == 0) {
            frontIndex = 0;
            rearIndex = 0;
        }
        else {
            rearIndex = (rearIndex + 1) % 10;
        }

        arr[rearIndex] = x;
        size++;
    }

    // remove from front
    void pop() {
        if(size == 0) {
            cout << "Queue Underflow";
            return;
        }
        
        if(size == 1) {     // only one element 
            frontIndex = -1;
            rearIndex = -1;
        }
        else {
            frontIndex = (frontIndex + 1) % 10;
        }
        size--;
    }

    // get front element
    int front() {
        if(size == 0) {
            cout << "Queue is Empty";
            return -1;
        }
        return arr[frontIndex];
    }

    // get rear element
    int back() {
        if(size == 0) {
            cout << "Queue is Empty";
            return -1;
        }
        return arr[rearIndex];
    }

    // get size
    int getSize() {
        return size;
    }

    // check empty
    bool empty() {
        return size == 0;
    }
};


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
class stackImp_LL {
    Node* top;
    int size;

    public:
    stackImp_LL() {
        top = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop() {
        if(top == nullptr) {
            cout << "Stack Underflow";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int topElement() {
        if(top == nullptr) {
            cout << "Stack is Empty";
            return -1;
        }
        return top->data;
    }

    int getSize() {
        return size;
    }

    bool empty() {
        return top == nullptr;
    }
};


class queueImp_LL {
    Node* start;
    Node* end;
    int size;

    public:
    queueImp_LL() {
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        if(start == nullptr) {
            start = temp;
            end = temp;
        }
        else {
            end->next = temp;
            end = temp;
        }
        size++;
    }

    void pop() {
        if(start == nullptr) {
            cout << "Queue Underflow";
            return;
        }
        Node* temp = start;
        start = start->next;
        delete temp;
        size--;

        if(size == 0) {
            end = nullptr;
        }
    }

    int front() {
        if(start == nullptr) {
            cout << "Queue is Empty";
            return -1;
        }
        return start->data;
    }

    int back() {
        if(end == nullptr) {
            cout << "Queue is Empty";
            return -1;
        }
        return end->data;
    }

    int getSize() {
        return size;
    }

    bool empty() {
        return start == nullptr;
    }
};


class stackUsingQueue {
    queue<int> q;

    public: 
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i=1; i<=s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if(q.empty()) {
            cout << "Stack Underflow";
            return;
        }
        q.pop();
    }

    int top() {
        if(q.empty()) {
            cout << "Stack is Empty";
            return -1;
        }
        return q.front();
    }

    int getSize() {
        return q.size();
    }

    bool empty() {
        return q.empty();
    }
};


class queueUsingStacks {
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        if(s1.empty()) {
            cout << "Queue Underflow";
            return;
        }

        s1.pop();
    }

    int front() {
        if(s1.empty()) {
            cout << "Queue is Empty";
            return -1;
        }

        return s1.top();
    }

    int getSize() {
        return s1.size();
    }

    bool empty() {
        return s1.empty();
    }
};


// approach 2
class queueUsindStacks {

};


class queueUsingStack {
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int x) {
        s1.push(x);
    }

    void pop() {
        if(s1.empty() && s2.empty()) {
            cout << "Queue Underflow";
            return;
        }

        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int front() {
        if(s1.empty() && s2.empty()) {
            cout << "Queue is Empty";
            return -1;
        }

        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    int getSize() {
        return s1.size() + s2.size();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

