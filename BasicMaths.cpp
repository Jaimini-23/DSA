#include <bits/stdc++.h>
using namespace std;

// for counting the number of digits in a number
void count(int n) {
    // method 1 by extracting the digits one by one
    // int count = 0;
    // while (n != 0) {
    //     n = n / 10;
    //     count++;
    // }
    // cout << count << endl;

    // method 2
    // int count = (int)log10(n) + 1;
    // cout << count << endl;

    // whenever you divide a n number by m, the time complexity is O(logm n).
    // so in this case the time complexity is O(log10 n) which is same as method 1 but the constant factor is less in method 2.
}


// for reversing a number
void reverse(int n) {
    // method 1 by extracting the digits one by one
    // int rev = 0;
    // while (n != 0) {
    //     int digit = n % 10;
    //     rev = rev * 10 + digit;
    //     n = n / 10;
    // }
    // cout << rev << endl;

    // method 2
    // string s = to_string(n);         // convert the number to string
    // reverse(s.begin(), s.end());
    // cout << s << endl;
}


// for checking whether a number is palindrome or not
void palindrome(int n) {
    // method 1 by extracting the digits one by one
    // int rev = 0, temp = n;
    // while (temp != 0) {
    //     int digit = temp % 10;
    //     rev = rev * 10 + digit;
    //     temp = temp / 10;
    // }
    // if (rev == n) {
    //     cout << "Palindrome" << endl;
    // } else {
    //     cout << "Not Palindrome" << endl;
    // }

    // method 2
    // string s = to_string(n);         // convert the number to string
    // string rev = s;                // copy the string to another variable
    // reverse(rev.begin(), rev.end());
    // if (s == rev) {
    //     cout << "Palindrome" << endl;
    // } else {
    //     cout << "Not Palindrome" << endl;
    // }

    // conversion of number to string and then checking for palindrome is not a good approach as it takes extra space and time for conversion. So method 1 is better than method 2.
    // the time complexity of method 1 is O(log10 n) and the space complexity is O(1).
    // int to string conversion takes O(log10 n) time and O(log10 n) space. So the overall time complexity of method 2 is O(log10 n) and the space complexity is O(log10 n).

    // int to string conversion way : string s = to_string(n);         // convert the number to string
    // string to int conversion way : int num = stoi(s);         // convert the string to number
    // string to long long conversion way : long long num = stoll(s);         // convert the string to long long
    // string to double conversion way : double num = stod(s);         // convert the string to double
}


// for checking whether a number is armstrong or not
void armstrong(int n) {
    // method 1 by extracting the digits one by one
    // int sum = 0, temp = n;
    // int count = (int)log10(n) + 1;     // count the number of digits in the number
    // while (temp != 0) {
    //     int digit = temp % 10;
    //     sum += pow(digit, count);       // calculate the sum of the cubes of the digits
    //     temp = temp / 10;
    // }
    // if (sum == n) {
    //     cout << "Armstrong" << endl;
    // } else {
    //     cout << "Not Armstrong" << endl;
    // }

    // method 2
    // string s = to_string(n);         // convert the number to string
    // int sum = 0;
    // for (char c : s) {
    //     int digit = c - '0';         // convert the character to integer
    //     sum += pow(digit, s.length());       // calculate the sum of the cubes of the digits
    // }
    // if (sum == n) {
    //     cout << "Armstrong" << endl;
    // } else {
    //     cout << "Not Armstrong" << endl;
    // }

    // conversion of number to string and then checking for armstrong is not a good approach as it takes extra space and time for conversion. So method 1 is better than method 2.
}


// for finding the divisors of a number
void divisors(int n) {
    // method 1 by extracting the digits one by one
    // for (int i = 1; i <= n; i++) {
    //     if (n % i == 0) {
    //         cout << i << " ";
    //     }
    // }
    // cout << endl;

    // method 2      
    // for (int i = 1; i <= sqrt(n); i++) {       // can also be written as i * i <= n and this is better than i <= sqrt(n) as it avoids the calculation of sqrt(n) in each iteration of the loop and also avoids the precision issues of sqrt(n) in case of perfect squares.
    //     if (n % i == 0) {
    //         cout << i << " ";
    //         if (i != n / i) {          // to avoid printing the square root twice in case of perfect square
    //             cout << n / i << " ";
    //         }
    //     }
    // }
    // cout << endl;

    // for example if n = 38, then the divisors are 1 38 2 19 by method 2 and 1 2 19 38 by method 1.

    // you will not get the divisors in sorted order in method 2, but you can sort them after finding all the divisors. So method 2 is better than method 1.
    // in case of non perfect square, sqrt(n) will take approximate and loop will run till the approximate value of sqrt(n) and in case of perfect square, loop will run till the exact value of sqrt(n). So in both cases the time complexity is O(sqrt(n)).
    // the time complexity of method 1 is O(n) and the time complexity of method 2 is O(sqrt(n)).
    // so method 2 is better than method 1.
}


// for checking whether a number is prime or not
void prime(int n) {
    // method 1 by extracting the digits one by one
    // if (n <= 1) {
    //     cout << "Not Prime" << endl;
    //     return;
    // }
    // for (int i = 2; i < n; i++) {
    //     if (n % i == 0) {
    //         cout << "Not Prime" << endl;
    //         return;
    //     }
    // }
    // cout << "Prime" << endl;

    // method 2
    // if (n <= 1) {
    //     cout << "Not Prime" << endl;
    //     return;
    // }
    // for (int i = 2; i <= sqrt(n); i++) {       // can also be written as i * i <= n and this is better than i <= sqrt(n) as it avoids the calculation of sqrt(n) in each iteration of the loop and also avoids the precision issues of sqrt(n) in case of perfect squares.
    //     if (n % i == 0) {
    //         cout << "Not Prime" << endl;
    //         return;
    //     }
    // }
    // cout << "Prime" << endl;

    // the time complexity of method 1 is O(n) and the time complexity of method 2 is O(sqrt(n)).
    // so method 2 is better than method 1.
}


// for finding the GCD of two numbers
void gcd(int a, int b) {
    // method 1 by extracting the digits one by one
    // while (a != b) {
    //     if (a > b) {
    //         a = a - b;
    //     } else {
    //         b = b - a;
    //     }
    // }
    // cout << a << endl;

    // method 2
    // while (b != 0) {
    //     int temp = b;
    //     b = a % b;
    //     a = temp;
    // }
    // cout << a << endl;

    // the time complexity of method 1 is O(max(a, b)) and the time complexity of method 2 is O(log(min(a, b))).
    // so method 2 is better than method 1.

    /* Euclidean Algorithm for finding GCD */

    // it states gcd(a,b) = gcd(a-b, b) if a > b and gcd(a,b) = gcd(a, b-a) if b > a and gcd(a,0) = a and gcd(0,b) = b.
    // we can also write it as gcd(a,b) = gcd(b, a % b) and gcd(a,0) = a and gcd(0,b) = b.
    // also gcd(a,b) = gcd(b%a, a) and gcd(0,a) = a and gcd(a,0) = a.
    
    // the time complexity of Euclidean Algorithm is O(log(min(a, b))) and the space complexity is O(1). Base of log is not fixed as it depends on the implementation of the algorithm. In general, it is considered to be O(log(min(a, b))) as it reduces the problem size by at least half in each iteration.
}




int main() {
    int n;
    cin >> n;
    count(n);
    reverse(n);
    palindrome(n);
    armstrong(n);
    divisors(n);
    prime(n);

    int m;
    cin >> m;
    gcd(n, m);
    return 0;
}