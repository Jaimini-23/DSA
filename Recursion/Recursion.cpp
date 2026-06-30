#include <bits/stdc++.h>
using namespace std;

// Recursion: When a function calls itself.
// Base case: The condition under which the recursion will stop.
// Recursive case: The condition under which the function will call itself.

// Stack overflow: When the function calls itself too many times, it can cause the program to crash due to running out of memory.
// In stack overflow the function don't have a base condition or the base condition is never reached. basically function do not complete its execution and keep on calling itself until the stack is full and the program crashes.
// Stack space: The amount of memory allocated for the function calls. Each time a function is called, a new stack frame is created to store the function's local variables and return address. If the function calls itself too many times, it can cause the stack to overflow and the program to crash.

// Segmentation fault: When the function tries to access memory that it is not allowed to access, it can cause the program to crash. This can happen when the function tries to access an array out of bounds or when it tries to dereference a null pointer.
// In recursion, stack overflow can lead to segmentation fault if the function tries to access memory that it is not allowed to access.

// Recursion Tree: visual representation of the recursive calls made by a function.

// When a while condition becomes false, the loop ends and execution continues after the loop; if the function ends there, control returns to the caller.
// and in if condition, return immediately exits the current function and returns control to the function that called it.

void name(int i,int n) {
    // When a while condition becomes false, the loop ends and execution continues after the loop; if the function ends there, control returns to the caller.
    // and in if condition, return immediately exits the current function and returns control to the function that called it.

    // WRONG!!
    // while(i<n) {
    //     cout << "mayank" << endl;
    //     name(i+1,n);
    // }

    //CORRECT!!
    // if(i<n) {
    //     cout << "mayank" << endl;
    //     name(i+1,n);
    // }

    // time complexity: O(n)
    // space complexity: O(n) (due to the call stack)
}


void num(int i,int n) {
    // if(i<=n) {
    //     cout << i << endl;
    //     num(i+1,n);
    // }

    // by backtracking;
    // if(i>0) {
    //     num(i-1,n);
    //     cout << i << endl;
    // }
}


void reverse_num(int i, int n) {
    // if(i<=0) return;
    // cout << i << endl;
    // reverse_num(i-1,n); 

    // by backtracking;
    // if(i<=n) {
    //     reverse_num(i+1,n);
    //     cout << i << endl;
    // }
}


// void sum(int n, int s) {
//     // if(n>0) sum(n-1,s+n);
//     // else cout << s;
// }

int sum(int n) {
    // if(n==0) return 0;
    // return n+sum(n-1);
}


int fact(int n) {
    // if(n==0) return 1;
    // return n*fact(n-1);
}


void arr_rev(int i,int n,int arr[]) {
    // if (i >= n/2) return;
    // swap(arr[i],arr[n-i-1]);
    // arr_rev(i+1,n,arr);

    //without swap function
    // if(i >= n/2) return;
    // int temp = arr[n-i-1];
    // arr[n-i-1] = arr[i];
    // arr[i] = temp;
    // arr_rev(i+1,n,arr);
}


bool palindrome(int i, string &s) {           // string &s is used to avoid creating a new copy of the string in every recursive call.
    // if(i >= s.size()/2) return true;
    // if(s[i] != s[s.size()-i-1]) return false;
    // return palindrome(i+1,s);
}


int fibo(int n) {                // time complexity: O(2^n) (exponential) because it makes two recursive calls for each non-base case, leading to a large number of calls as n increases.
    // if(n <= 1) return n;               // space complexity: O(n) (due to the call stack) because the maximum depth of the recursion is n.
    // return fibo(n-1) + fibo(n-2);
}


int main() {
    int n;
    cin >> n;
    // name(0,n);
    // num(n,n);
    // reverse_num(1,n);
    // // cout << sum(n);
    // cout << fact(n);

    // int arr[n];
    // for(int i=0;i<n;i++) cin >> arr[i];
    // arr_rev(0,n,arr);
    // for(int i=0;i<n;i++) cout << arr[i] << " ";

    // string s = "madsm";
    // cout << palindrome(0,s);

    // 1 1 2 3 5 8 13 21 34 ....
    // cout << fibo(n); 
    
    return 0;
}

