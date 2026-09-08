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




int main() {
    // string s = "a+b*(c^d-e)";
    // string result = infixToPostfix(s);
    // string result = infixToPrefix(s);
    string s = "ab+c*de-f/*";
    string result = postfixToInfix(s);
    for(auto it: result) cout << it;
    return 0;
}




