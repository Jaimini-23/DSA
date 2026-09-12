#include <bits\stdc++.h>
using namespace std;


bool validParenthesis(string str) {
    // TC: O(n) and SC: O(n)
    stack<char> st;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        }
        else {
            if(st.empty()) return false;
            if((st.top() == '(' && str[i] == ')') ||
                (st.top() == '{' && str[i] == '}') ||
                (st.top() == '[' && str[i] == ']')) {
                    st.pop();
            }
            else return false;
        }
    }
    return st.size() == 0;
}


int priority(char ch) {
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    return -1;
}
string infixToPostfix(string s) {
    // TC: O(n) and SC: O(n)
    stack<char> st;
    string ans = "";
    for(int i=0; i<s.size(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
        }

        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while(!st.empty() && st.top() != '(' &&
                (priority(s[i]) < priority(st.top()) ||
                (priority(s[i]) == priority(st.top()) && s[i] != '^'))) {
    
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}


string infixToPrefix(string s) {
    // TC: O(n) and SC: O(n)
    // Reverse the infix expression.
    // Swap '(' with ')'.
    // Convert the modified expression to postfix.
    // Reverse the postfix result → Prefix.
    reverse(s.begin(),s.end());       // reverse
    for(int i=0; i<s.size(); i++) {      // swap '(' and ')'
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }

    string ans = "";
    stack<char> st;
    for(int i=0; i<s.size(); i++) {                 // convert into postfix
        if((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
        }

        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while(!st.empty() && st.top() != '(' &&
            priority(s[i]) < priority(st.top())) {

                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());      // reverse ans
    return ans;
}


string postfixToInfix(string s) {
    // TC: O(n) + O(n)_can be for string concatination and SC: O(n)
    // if operator, then put it in between last two operand
    stack<string> st;
    for(int i=0; i<s.size(); i++) {
        if(isalnum(s[i])) {         
            string operand = "";      // converting char into string, to push in stack<string>
            operand += s[i];
            st.push(operand);
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string expression = "(" + t2 + s[i] + t1 + ")";
            st.push(expression);
        }
    }
    return st.top();
}


string prefixToInfix(string s) {
    // TC: O(n) + O(n)_can be used for string concatenation
    // SC: O(n)
    // Traverse from right to left.
    // If an operator is found, place it between the top two operands.
    stack<string> st;
    for(int i=s.size()-1; i>=0; i--) {
        if(isalnum(s[i])) {         
            string operand = "";      // converting char into string, to push in stack<string>
            operand += s[i];
            st.push(operand);
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string expression = "(" + t1 + s[i] + t2 + ")";
            st.push(expression);
        }
    }
    return st.top();
}


string postfixToPrefix(string s) {
    // TC: O(n) + O(n)_can be for string concatination and SC: O(n)
    stack<string> st;
    for(int i=0; i<s.size(); i++) {
        if(isalnum(s[i])) {         
            string operand = "";
            operand += s[i];
            st.push(operand);
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            // operator + t2 + t1
            string expression = s[i] + t2 + t1;         // eg. -bc,+de
            st.push(expression);
        }
    }
    return st.top();
}


string prefixToPostfix(string s) {
    // TC: O(n) + O(n)_can be for string concatination and SC: O(n)
    stack<string> st;
    for(int i=s.size()-1; i>=0; i--) {
        if(isalnum(s[i])) {         
            string operand = "";
            operand += s[i];
            st.push(operand);
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            // t1 + t2 + operator
            string expression = t1 + t2 + s[i];
            st.push(expression);
        }
    }
    return st.top();
}


vector<int> nextGreaterElement(vector<int> &arr) {
    // Brute (TC: O(n^2) and SC: O(n)_nge)
    // vector<int> nge(arr.size(),-1);       // {-1,-1,-1,.....,-1}
    // for(int i=0; i<arr.size(); i++) {
    //     for(int j=i+1; j<arr.size(); j++) {
    //         if(arr[j] > arr[i]) {
    //             nge[i] = arr[j];
    //             break;
    //         }
    //     }
    // }
    // return nge;

    // Optimal (TC: O(2n) and SC: O(n) + O(n))
    stack<int> st;
    vector<int> nge(arr.size(),-1);
    for(int i=arr.size()-1; i>=0; i--) {
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        if(st.empty()) nge[i] = -1;       // or else use continue, because we already have default vector values as -1
        else nge[i] = st.top();
        st.push(arr[i]);
    }
    return nge;
}




int main() {
    // string s = "a+b*(c^d-e)";
    // string result = infixToPostfix(s);
    // string result = infixToPrefix(s);
    // string s = "ab+c*de-f/*";
    // string result = postfixToInfix(s);

    // string s = "*/ab-cd";
    // string result = prefixToInfix(s);
    // string s = "ab-cd-*";
    // string result = postfixToPrefix(s);

    // string s = "*+abc";
    // string result = prefixToPostfix(s);
    // for(auto it: result) cout << it;

    vector<int> arr = {6,0,8,1,3};
    arr = nextGreaterElement(arr);
    for(auto it : arr) cout << it <<" ";
    return 0;
}




