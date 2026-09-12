#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int coeff;
    int expo;
    Node* next;
    Node(int c,int e) {
        coeff = c;
        expo = e;
        next = NULL;
    }
};


void insert(Node* &head,int coeff,int expo) {
    if(coeff == 0) return;
    Node* newNode = new Node(coeff,expo);
    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp != NULL) {
        if(temp->expo == expo) {
            temp->coeff += coeff;
            return;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


Node* addition(Node* head1,Node* head2) {
    Node* head = NULL;

    Node* t1 = head1;
    Node* t2 = head2;
    while(t1 != NULL && t2 != NULL) {
        if(t1->expo == t2->expo) {
            int coeff = t1->coeff + t2->coeff;

            if(coeff != 0) {
                insert(head,coeff,t1->expo);
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        else if(t1->expo < t2->expo) {
            insert(head,t2->coeff,t2->expo);
            t2 = t2->next;
        }

        else {
            insert(head,t1->coeff,t1->expo);
            t1 = t1->next;
        }
    }

    while(t1) {
        insert(head,t1->coeff,t1->expo);
        t1 = t1->next;
    }
    while(t2) {
        insert(head,t2->coeff,t2->expo);
        t2 = t2->next;
    }
    return head;
}


Node* multiplication(Node* head1,Node*head2) {
    Node* t1 = head1;
    Node* result = NULL;
    while(t1 != NULL) {
        Node* t2 = head2;
        while(t2 != NULL) {
            int coeff = t1->coeff * t2->coeff;
            int expo = t1->expo + t2->expo;
            insert(result,coeff,expo);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return result;
}


Node* subtraction(Node* head1,Node* head2) {
    Node* result = NULL;

    Node* t1 = head1;
    Node* t2 = head2;
    while(t1 != NULL && t2 != NULL) {
        if(t1->expo == t2->expo) {
            int coeff = t1->coeff - t2->coeff;

            if(coeff != 0) {
                insert(result,coeff,t1->expo);
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        else if(t1->expo < t2->expo) {
            insert(result,-t2->coeff,t2->expo);
            t2 = t2->next;
        }

        else {
            insert(result,t1->coeff,t1->expo);
            t1 = t1->next;
        }
    }

    while(t1) {
        insert(result,t1->coeff,t1->expo);
        t1 = t1->next;
    }
    while(t2) {
        insert(result,t2->coeff,t2->expo);
        t2 = t2->next;
    }
    return result;
}


int evaluate(Node* head,int x) {
    int result = 0;
    Node* temp = head;
    while(temp != NULL) {
        result += temp->coeff * pow(x,temp->expo);
        temp = temp->next;
    }
    return result;
}




