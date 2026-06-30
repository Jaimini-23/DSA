#include <bits/stdc++.h>
using namespace std;

// Hashing is a technique used to store and retrieve data efficiently by mapping keys (numbers, characters, strings, etc.) to specific indices using a hash function.

// A local array is stored on the stack (typically limited to a few MB, so around 10^6 integers and may cause stack overflow if exceeded),
// while a global array is stored in the data/BSS segment (which can typically hold much larger arrays (10^7), often up to several GB, depending on the system). Therefore, using a global array allows for much larger sizes without risking stack overflow.
// We cannot hash numbers using array which are of 10^8,10^10,etc. So we use map and unordered map(STL).

// 1.Number Hashing
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     int hash[20] = {0};          // initial all elements as 0
//     for(int i=0;i<n;i++) {
//         cin >> arr[i];
//         hash[arr[i]] +=1;          // precompute
//     }

//     int q;
//     cin >> q;
//     while(q--) {
//         int number;
//         cin >> number;

//         // fetch
//         cout << hash[number] << endl;
//     }
//     return 0; 

//     // Time Complexity
//     // Building the hash table: O(n)
//     // Answering each query: O(1)
//     // So for q queries:
//         // O(n)+O(q)
//     // Space Complexity = O(maximum value of hash array)
// }


// 2.Character Hashing
// int main() {
//     string s;
//     cin >> s;
//     int hash[26]={0};          // 26 to store frequency of all alphabets
//     for(char ch:s) {
//         ch=tolower(ch);         // taking care of upper case letters
//         hash[ch-'a']++;      // placing them according to the ASCII values
//     }

//     // for seperate 'A' and 'a'
//     // string s;
//     // cin >> s;
//     // int hash[256] = {0};
//     // for (char c : s) hash[c]++;

//     int q;
//     cin >> q;
//     while(q--) {
//         char ch;
//         cin >> ch;
//         cout << hash[ch-'a'] << endl;
//     }
//     return 0;
// }


// We cannot hash numbers using array (array hashing) which are of 10^8,10^10,etc. So we use map and unordered map(STL).
// Map use less memory and do not store useless keys like array has because of index.
// like in arr[1,2,3,12], arr store arr[4] as 0 and simillarly for 5,6,7,....11
// Map does not store them it automatically throws 0. So it is beneficial.
// But take care that map stores all the values in sorted form.


// Number Hashing by map
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];  
//     map<int,int> mpp;             // for character hashing, map<char,int>
//     for(int i=0;i<n;i++) {
//         cin >> arr[i];
//         mpp[arr[i]]++;            // mpp[s[i]]++;
//     }

//     int q;
//     cin >> q;
//     while(q--) {
//         int number;
//         cin >> number;

//         // fetch
//         cout << mpp[number] << endl;
//     }
//     return 0;
// }

 
// we generally use unordered map because it's time complexity is O(1) but
// in worst case due to internal collisions time complexity becomes O(n), then better to use map instead of unordered map (O(log n))
// key can be any data structure in map but in unordered map <pair<int,int>,int> and all is not allowed,it ristrict to long long, double, etc.


// int main() {
//     int n;
//     cin >> n;
//     int arr[n];  
//     unordered_map<int,int> mpp;          // for character hashing, unordered_map<char,int>
//     for(int i=0;i<n;i++) {
//         cin >> arr[i];
//         mpp[arr[i]]++;            // mpp[s[i]]++;
//     }

//     int q;
//     cin >> q;
//     while(q--) {
//         int number;
//         cin >> number;

//         // fetch
//         cout << mpp[number] << endl;
//     }
//     return 0;
// }


// Division Method in Hashing
// The division method computes the hash value by taking the remainder when a key is divided by the size of the hash table.

// int main() {
//     int m = 10;  // hash table size
//     vector<int> hashTable[m];

//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         int key;
//         cin >> key;

//         int index = key % m;   // Division Method
//         hashTable[index].push_back(key);
//     }

//     // Display hash table
//     for (int i = 0; i < m; i++) {
//         cout << i << " -> ";
//         for (int x : hashTable[i]) {
//             cout << x << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// Collisions
// In hashing, a collision occurs when two or more keys are mapped to the same hash index.
// for example: 23 % 10 = 3 and 83 % 10 = 3, Both keys map to index 3, so a collision occurs.


