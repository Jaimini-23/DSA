#include <bits/stdc++.h>
using namespace std;

/* Containers and Iterators in STL */

// Pair
void pairs() {
    // pair<int,int> p={1,3};
    // cout << p.first << " " << p.second;

    // Nested Pair
    // pair<int, pair<int ,int>> p={4,{3,2}};
    // cout << q.first << " " << q.second.second << " " << q.second.first;

    // pair<int,int> arr[] = {{1,3}, {2,3}, {3,4}, {4,5}};
    // cout << arr[1].second;

    // Error!
    // pair<int,int,int> p={1,2,3};
    // cout << p.third;
}


// Vector
void vectors() {
    // We mainly use vectors when we don't know the size of data type/no of elements, because array has fixed size and cannot change it further.
    // But in vectors you can change the size.

    // vector<int> v;    // {}
    // v.push_back(1);   // {1}
    // v.emplace_back(5);   //{1,5}    // emplace_back is faster than push_back 
    // cout << v[1];        // 5  
    // cout << v.at(0);     // simillar like v[0]

    // vector<pair<int,int>> v;
    // v.push_back({2,3});
    // v.emplace_back(1,4);   // do not use curly brackets while emplace_back !!

    // vector<int> v(5,100);      // {100, 100, 100, 100, 100}  5 times 100  //size = 5 int elements 
    // vector<int> v(5);          // {0,0,0,0,0}  5 times 0
    // vector<int> v(6);          // we fix the size but may increase using push_back and make size 7 and so on !!

    // vector<int> v1(5,20);   
    // vector<int> v2(v1);       // copy of v1, e.i. {20,20,20,20,20}

    // Another way to access elements of a vector is by position address (by iterators)
    // vector<int> v={10,20,30};
    // vector<int>::iterator it=v.begin();   // v.begin points towards the first memory address of the element
    // it++;      // points to the next element
    // cout << *(it);

    // vector<int>::iterator it=v.end();   // v.end does not points to the last element, it points beyond the last element
    // it--;   // Now this points to the last element;

    // vector<int>::reverse_iterator it=v.rend();   // reverse of v.end() i.e. points before the first element, it-- points to first element
    // it--;
    // cout << *(it);
    
    // vector<int>::reverse_iterator it=v.rbegin();   //pointd to the last element and it++ (moves backward) moves to second last (not to beyond of vector) and so on.
    // it++;
    // cout << *(it);

    // vector<int>::iterator it=v.back();   // WRONG!!
    // vector<int> v={10,20,30};
    // int m=v.back();  
    // cout << m;     // can directly also take cout << v.back();


    // vector<int> v={10,20,30};
    // for(vector<int>::iterator it=v.begin(); it != v.end(); it++) {
    //         cout << *(it) << " ";
    // }

    // vector<int>::reverse_iterator or vector<int>::iterator can be written as auto
    // vector<int> v = {1,2,3,4};
    // auto it1 = v.begin();   // iterator
    // auto it2 = v.rbegin();  // reverse_iterator

    // vector<int> v={10,20,30};
    // for(auto it=v.begin(); it != v.end(); it++) {
    //     cout << *(it) << " ";                              // auto will read and assign iterator data type to it variable
    // }

    // more simpler
    // vector<int> v={1,2,3,4};
    // for(auto it : v) {
    //     cout << it << " ";           // here auto consider it as int and that's why we don't use *(it)
    //     // cout << *(it) << " ";     // ERROR!!
    // }

    // Erase/deletion an element
    // vector<int> v={1,2,3,4};
    // v.erase(v.begin()+1);          // erase's the 2nd element (remove 2)
    // v.erase(v.begin()+2);          // erase's the element from remaining vector ({1,3,4}), so remove 4 instead 3
    // for(auto it : v)  cout << it << " ";

    // for removing multiple elements in a row
    // v.erase(v.begin()+1, v.begin()+3);     // v.erase(start.end), start is included but end is not included in erase
    // for(auto it : v)  cout << it << " ";


    // Insert function
    // vector<int> v(3,100);                         // 100 100 100
    // v.insert(v.begin(),30);                     // 30 100 100 100 
    // v.insert(v.begin()+2,300);                   //30 100 300 100 100 
    // v.insert(v.begin()+1,2,10);                     //30 10 10 100 300 100 100 
    // for(auto it : v)  cout << it << " ";

    // vector<int> v2(3,50);
    // v.insert(v.begin(),v2.begin(),v2.end());       //50 50 50 30 10 10 100 300 100 100


    // vector<int> v={1,2,3,4};
    // cout << v.size();        // returns the number of elements in the vector, i.e. 4 in this case

    // v.pop_back();               //removes.pops out the last element      // 1,2,3  
    // for(auto it : v)  cout << it << " ";

    // vector<int> v1={10,20};
    // vector<int> v2={30,40};
    // v1.swap(v2);                  // v1 -> {30,40} and v2 -> {10,20}
    // for(auto it : v1)  cout << it << " ";            // 30 40 
    // cout << endl;
    // for(auto it : v2)  cout << it << " ";            // 10 20 

    // vector<int> v={10,20,30};
    // v.clear();                      // erases the entire vector
    // cout << v.empty();              // Gives 1 (True) if vector is empty or 0 (False) if vector is not empty
    
}


// List
void lists() {
    // list<int> ls();    // Not a list object, It declares a function named ls that returns list<int> and takes no arguments. so list function like push_back and all will not work
    // list<int> ls;       //Correct way to create a list

    // Correct ways to create an empty list
    // list<int> ls;
    // list<int> ls{};
    // list<int> ls = list<int>();


    // list<int> ls;
    // ls.push_back(2);        // {2}     //push_back() creates a temporary object first, then inserts it. emplace_back()constructs the object directly inside the node.
    // ls.emplace_back();     // {2,0}        // push_back() cannot be called without an argument but emplace_back() can work without arguments if the type has a default constructor.
    // ls.push_front(5);       // {5,2,0}    // In a list, push_front() is cheaper than insert function because it always inserts at the beginning directly.
    // ls.emplace_front(6);     // {6,5,2,0}
    // for(auto it:ls) cout << it << " ";

    // Some different special list functions  push_front(), pop_front(), merge(), splice(), sort(), reverse(), remove(), unique(), ...
    // And some vector features do not exist in list: ls[0], ls.at(0), because lists do not support random access.

    // Rest many functions are simillar to Vector functions, like begin, end, rbegin, rend, clear, swap, insert, size, ...
}


// Deque
void deques() {
    // deque<int> dq;

    // dq.push_back(1);      // {1}
    // dq.emplace_back(2);   // {1, 2}

    // dq.push_front(4);     // {4, 1, 2}
    // dq.emplace_front(3);  // {3, 4, 1, 2}
    // for(auto it : dq)  cout << it << " ";

    // dq.pop_back();        // {3, 4, 1}
    // dq.pop_front();       // {4, 1}

    // deque<int> dq={10,20,30};
    // dq.back();            // returns the last element of the deque
    // dq.front();           // returns the first element of the deque
    // cout << dq.front() << endl;       // 10
    // cout << dq.back();                // 30

    // Vector stores elements in contiguous memory, deque stores them in multiple memory blocks (not contiguous).
    // Additional functions: push_front(), pop_front(), emplace_front(), ...
    
    // Cache performance means: How efficiently data is accessed from the CPU cache. CPU cache is a very fast small memory near the processor.
    // Better cache performance means faster access due to contiguous memory storage.
    // Vector has better cache performance because elements are stored contiguously in memory.
    // Deque has slightly lower cache performance because elements are stored in multiple memory blocks.

    // Rest many functions are simillar to Vector functions, like begin, end, rbegin, rend, clear, swap, insert, size, ...
}


// Stack
void stacks() {
    // It provides only LIFO operations (Last In First Out)

    // stack<int> st={1,2,3};     // ERROR!!
    // deque<int> dq = {1,2,3};
    // stack<int> st(dq);


    // stack<int> st;
    // st.push(1);            // {1}
    // st.push(5);            // {5,1}
    // st.emplace(7);         // {7,5,1}
    // cout << st.top();      // 7        // accessing through indexing is not allowed, i.e. st[2] is invalid

    // st.pop();              // {5,1}    // pop's out the first element 
    // cout << st.size();     // 2        // number of elements in the stack
    // cout << st.empty();    // 0        // Gives 1 (True) if stack is empty or 0 (False) if stack is not empty

    // stack<int> st1,st2;
    // st1.swap(st2);

    // for(auto it:st)  cout << it << " ";   // ERROR!!        // Auto can be used error is not because of that. stack does not expose iterators, So traversal is not allowed directly.
    // while(!st.empty()) {                  // Correct Way!!
    // cout << st.top() << " ";
    // st.pop();
    // }

    // Stack restricts access to only the top element, unlike vector/list which allow traversal and random operations.
}


// Queue
void queues() {
    // It provides only FIFO operations (First In First Out)

    // queue<int> q={1,2,3};    // ERROR!!
    // deque<int> dq = {1,2,3};
    // queue<int> q(dq);

    //stack<int, list<int>> st;
    //queue<int, list<int>> q; 
    //stack<int, vector<int>> st;     // But only stack can use vector

    // queue<int> q;
    // q.push(1);         // {1}
    // q.push(2);         // {1,2}
    // q.emplace(3);      // {1,2,3}

    // q.back() += 5;     // go to last element and add 5 to its value
    // cout << q.back();        // 8
    // cout << q.front();       // returns first element of the queue

    // q.pop();              // pop's out first element
    
    // for(auto it : q)    // ERROR!!    // because queue has no iterators
    // while(!q.empty()) {                        // Correct
    // cout << q.front() << " ";
    // q.pop();
    // }

    // queue<int> temp = q;             // If you want to keep original queue
    // while(!temp.empty()) {
    //     cout << temp.front() << " ";
    //     temp.pop();
    // }

    // size, swap, empty functions are same as stack
}


// Priority_queue
void priority_queues() {
    // Special type of queue where the largest element gets highest priority by default.
    // Priority queue stores elements in sorted priority order, not insertion order.
    
    // Maximum Heap
    // priority_queue<int> pq;
    // pq.push(5);    // {5}
    // pq.push(2);    // {5,2}
    // pq.push(8);    // {8,5,2}
    // pq.emplace(10);    // {10,8,5,2}

    // cout << pq.top();          // 10
    // pq.pop();             // pop's out the first element 
    // cout << pq.top();          // 8

    // Minimum Heap
    // priority_queue<int, vector<int>, greater<int>> pq;
    // pq.push(5);    // {5}
    // pq.push(2);    // {2,5}
    // pq.push(8);    // {2,5,8}
    // pq.emplace(10);    // {2,5,8,10}

    // cout << pq.top();          // 2
    // pq.pop();             // pop's out the first element 
    // cout << pq.top();          // 5

    // while(!pq.empty()) {               // for traversing
    // cout << pq.top() << " ";
    // pq.pop();
    // }

    // size, swap, empty functions are same as others

}


// Set
void sets() {
    // Stores unique elements only
    // Elements are automatically sorted
    // Implemented using balanced BST (Binary Search Tree)

    // set<int> s;
    // s.insert(2);     // {2}
    // s.emplace(3);    // {2,3}
    // s.insert(1);    // {1,2,3}
    // s.insert(2);    // {1,2,3}
    // for(auto it : s)   cout << it << " ";        // {1,2,3}

    // set<int> s={10,20,30};
    // auto it = s.find(30);       // // find() returns an iterator to the element if found, otherwise it returns s.end()
    // cout << *it;                // 30
    // auto it = s.find(500);          // 3
    // cout << *it; 

    // set<int> s={10,20,30};
    // s.erase(20);                 // erase 20    // takes logarithmic time   // erase(element) or erase(iterator)
    // for(auto it : s)  cout << it << " ";      // {10, 30}       // all similar to vectors like erase[start,end) for a range of deletion
    // s.erase(200);                 // {10,30}
    // for(auto it : s)  cout << it << " ";         

    // set<int> s={1,2,3,4};
    // int count = s.count(1);       // It should be only 1 time in the set if exist in it according to the defination
    // cout << count;     // 1                  // 1 -> exists    //0 -> does not exist

    // Lower bound(x) : First element >= x   and    Upper bound(x) : First element > x      // it == st.end() if no such element exists.
    // set<int> st = {1,2,4,5,7};
    // auto it1 = st.lower_bound(2);       // 2
    // auto it2 = st.upper_bound(3);       // 4
    // auto it3 = st.upper_bound(7);      // 5
    // cout << *it1 << endl;
    // cout << *it2 << endl;
    // cout << *it3;

    // Set elements cannot be modified directly.
    // set<int, greater<int>> st;       // Descending order set

    // Rest many functions are simillar to Vector functions, like begin, end, rbegin, rend, clear, swap, insert, size, ...
}


// Multiset
void multisets() {
    // Similar to set, but it allows duplicate elements.
    // Implemented using balanced BST (Binary Search Tree)
    // count(x) can be many
    
    // multiset<int> ms;
    // ms.insert(10);  // {10)
    // ms.insert(20);  // {10,20}
    // ms.insert(10);  // {10,10,20}
    // ms.insert(30);  // {10,10,20,30}
    // for(auto it : ms)  cout << it << " ";

    // erase(element) and erase(iterator)
    // multiset<int> ms={10,10,20,30,40};
    // ms.erase(10);                  // removes all 10's
    // ms.erase(ms.find(10));         // to remove only one occurrence. ms.find(10) points to the first occurrence of 10, So only the first 10 is erased.
    // ms.erase(ms.find(10), ms.find(10)+2);      // erase[start,end) for a range of erase

    // Rest all functions are same as sets
}


// Unordered Set
void unordered_sets() {
    // Stores unique elements, but unlike set, elements are not sorted. Order is unpredictable
    // Implemented using hashing
    // lower_bound() and upper_bound() are not available in unordered_set

    unordered_set<int> us;

    // TIme Complexity
    // set -> sorted + slower (log n)
    // unordered_set -> unsorted + faster (average O(1)), Worst case for unordered_set is O(n) because hash collisions may occur.

    // Rest all functions are simillar to sets
}


// Map
void maps() {
    // key -> value pair
    // Keys are unique and automatically sorted
    // Implemented using balanced BST (Binary Search Tree)

    // Many ways to define 
    // map<int, int> mp;
    // map<int, string> mp;
    // map<int, pair<int, pair<int, int>>> mp;

    // mp[key] = value;
    // mp.insert({1,"Apple"});

    // map<int, string> mp;
    // mp[1] = "Apple";          // stored as 1 -> Apple, 2 -> Banana, 3 -> Mango
    // mp[2] = "Banana";
    // mp[3] = "Mango";
    // for(auto it : mp) {
    // cout << it.first << " " << it.second << endl;
    // }

    // map<int,int> mp;         // map stores keys in sorted order
    // mp[3] = 30;
    // mp[1] = 10;
    // mp[2] = 20;
    // for(auto it : mp) {                                        // 1 10
    // cout << it.first << " " << it.second << endl;              // 2 20
    // }                                                          // 3 30


    // map<int, int> mp={{1,10}, {2,20}, {3,30}};
    //cout << mp[1];     // 10
    //cout << mp[5];     // 0, because mp[5] creates a new key 5 with default value 0 (for int) and returns it. So it does not return an error but gives 0 as output.
    //mp.at(5);          // ERROR!! because at() does not create a new key and throws an out_of_range exception if the key does not exist.
    // if not found the key in map, mp.find(key) returns an iterator to the end of the map (mp.end()), So we can check if a key exists by comparing the iterator with mp.end().
    // in map<int ,string> default value of string is "" (empty string), and in map<int, pair<int, int>> default value is {0,0} (pair of 0's) and for map<int, char> default value is '\0' (null character) and so on for other data types.

    
    // auto it = mp.find(3);
    // cout << (*it).second;         // 30
    // cout << it->second;           // 30, because it is an iterator pointing to a pair, so we can use -> operator to access the second element of the pair directly.
    // auto it = mp.find(5);         // mp.end() because 5 is not found in the map
    // cout << (it == mp.end());     // 1 (True) if not found, 0 (False) if found

    // auto it = mp.lower_bound(2);     // lower_bound(x) returns an iterator to the first element with key >= x, So it will return an iterator pointing to the element with key 2, which is 20 in this case.
    // auto it = mp.upper_bound(3);     // upper_bound(x) returns an iterator to the first element with key > x, So it will return an iterator pointing to the element with key greater than 3, which is mp.end() in this case because there is no key greater than 3 in the map.

    // set, multiset, map -> O(log n) for insert, find, erase in both average and worst cases (Balanced BST)
    // unordered_set, unordered_map -> Average O(1), Worst O(n) for insert, erase, find (Hashing collisions)
    

    // erase, swap, size, empty are same as above
}


// Multimap
void multimaps() {
    // Similar to map, but it allows duplicate keys. So multiple values can be associated with the same key.
    // Keys are automatically sorted, but values can be duplicated for the same key. So mp[key] will not work for multimap because it returns a single value, but there can be multiple values for the same key in multimap. So we have to use equal_range() function to get the range of values for a specific key.
    // Implemented using balanced BST (Binary Search Tree)

    // multimap<int, string> mp;
    // mp.insert({1,"Apple"});
    // mp.insert({2,"Banana"});
    // mp.insert({1,"Mango"});     // duplicate key 1 with different value "Mango"
    // for(auto it : mp) {                                         // 1 Apple
    // cout << it.first << " " << it.second << endl;               // 1 Mango
    // }                                                           // 2 Banana
    
    // equal_range(key) returns a pair of iterators, where the first iterator points to the first occurrence of the key and the second iterator points to the position just after the last occurrence of the key. So we can iterate through this range to get all values associated with that key.
    // auto range = mp.equal_range(1);     // range of key 1, which has two values "Apple" and "Mango"       // range.first points to the first occurrence of key 1 (1 Apple) and range.second points to the position just after the last occurrence of key 1 (after 1 Mango), so range is [1 Apple, 1 Mango) in terms of iterators.
    // for(auto it = range.first; it != range.second; it++) {
    //     cout << it->first << " " << it->second << endl;           // 1 Apple
    // }                                                             // 1 Mango

    // Rest all functions are simillar to maps
}


// Unordered Map
void unordered_maps() {
    // Similar to map, but keys are not sorted. Order is unpredictable.
    // Implemented using hashing
    // lower_bound() and upper_bound() are not available in unordered_map

    unordered_map<int, string> ump;

    // Time Complexity
    // map -> sorted + slower (log n)
    // unordered_map -> unsorted + faster (average O(1)), Worst case for unordered_map is O(n) because hash collisions may occur.

    // Rest all functions are simillar to maps
}



/* Algorithms in STL */

void Extra() {

    // sort(a,a+n);     // sort in ascending order where a is the first element of the array and n is the number of elements in the array
    // sort(a+2,a+5);   // sort from index 2 to index 4 (5 is not included) in ascending order
    // sort(a,a+n,greater<int>());     // sort in descending order

    // sort(v.begin(), v.end());     // sort a vector in ascending order
    // sort(v.begin()+1, v.end()-1);   // sort from index 1 to index n-2 (n-1 is not included) in ascending order
    // sort(v.begin(), v.end(), greater<int>());     // sort a vector in descending order
    
    // sort(s.begin(), s.end());     // sort a string in ascending order (lexicographical order)
    // sort(s.begin(), s.end(), greater<char>());     // sort a string in descending order (reverse lexicographical order)

    // For sorting pairs, it sorts first by the first element, and if there is a tie, then by the second element.
    // sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());     // sort a vector of pairs in descending order

    // reverse(a, a+n);     // reverse an array
    // reverse(v.begin(), v.end());     // reverse a vector

    // If you have to sort in a custom way, then you can create a comparator function and pass it to the sort function.
    // bool cmp(pair<int, int> a, pair<int, int> b) {
    //     // Custom comparison logic
    // }
    // sort(pairs.begin(), pairs.end(), cmp);     // sort a vector of pairs using a custom comparator function


    // int num=7;
    // int count = __builtin_popcount(num);     // returns the number of set bits (1's) in the binary representation of num
    // cout << count << endl;        // For num=7 (binary 111), it will return 3 because there are three set bits in 7.

    // long long num = 15;
    // int count = __builtin_popcountll(num);   // returns the number of set bits (1's) in the binary representation of num for long long data type
    // cout << count << endl;        // For num=15 (binary 1111), it will return 4 because there are four set bits in 15.

    // next_permutation() and prev_permutation() functions are used to generate the next or previous lexicographical permutation of a sequence.
    // vector<int> v = {1, 2, 3};
    // next_permutation(v.begin(), v.end());     // generates the next lexicographical permutation
    // prev_permutation(v.begin(), v.end());     // generates the previous lexicographical permutation

    // next_permutation() rearranges the elements into the next lexicographically greater permutation. If such a permutation is not possible (i.e., the current arrangement is the highest possible), it rearranges the elements to the lowest possible order (i.e., sorted in ascending order).
    // prev_permutation() rearranges the elements into the previous lexicographically smaller permutation. If such a permutation is not possible (i.e., the current arrangement is the lowest possible), it rearranges the elements to the highest possible order (i.e., sorted in descending order).

    // For example, if we have a vector v = {1, 2, 3}, the next_permutation will generate the following sequence of permutations:
    // 1. {1, 2, 3} (initial)
    // 2. {1, 3, 2}
    // 3. {2, 1, 3}
    // 4. {2, 3, 1}
    // 5. {3, 1, 2}
    // 6. {3, 2, 1}

    // After the last permutation {3, 2, 1}, calling next_permutation again will rearrange it back to the lowest order {1, 2, 3}.
    // Similarly, if we start with {3, 2, 1} and call prev_permutation, it will generate the following sequence of permutations:
    // 1. {3, 2, 1} (initial)
    // 2. {3, 1, 2}
    // 3. {2, 3, 1}
    // 4. {2, 1, 3}
    // 5. {1, 3, 2}
    // 6. {1, 2, 3}

    // After the last permutation {1, 2, 3}, calling prev_permutation again will rearrange it back to the highest order {3, 2, 1}.

    // Anotheter example: 
    // string s = "abc";
    // do {
    //     cout << s << endl;     // This will print all permutations of the string "abc" in lexicographical order
    // } while (next_permutation(s.begin(), s.end()));
    // Output:
    // abc
    // acb
    // bac
    // bca
    // cab
    // cba

    // returns false at the last permutation and rearranges the string to the lowest order (sorted in ascending order)

    
    // int maximum = *max_element(a,a+n);     // returns the maximum element in the array a of size n or in a range or in a vector v, it would be max_element(v.begin(), v.end());    
    // int minimum = *min_element(a,a+n);     // returns the minimum element in the array a of size n or in a range or in a vector v, it would be min_element(v.begin(), v.end());

    // int sum = accumulate(a, a+n, 0);     // returns the sum of all elements in the array a of size n or in a range or in a vector v, it would be accumulate(v.begin(), v.end(), 0);
    // here 0 is the initial value of the sum, so it starts with 0 and adds all elements to it. If we want to calculate the product instead of sum, we can use 1 as the initial value and multiply all elements to it, like this: accumulate(a, a+n, 1, multiplies<int>());

    // count(a, a+n, x);     // returns the number of occurrences of x in the array a of size n or in a range or in a vector v, it would be count(v.begin(), v.end(), x);
    // count_if(a, a+n, condition);     // returns the number of elements in the array a of size n that satisfy the given condition or in a range or in a vector v, it would be count_if(v.begin(), v.end(), condition);
    // Here condition is a function that takes an element as input and returns true if the element satisfies the condition, otherwise it returns false.
}


 

int main() {
    pairs();
    vectors();
    lists();
    deques();
    stacks();
    queues();
    priority_queues();
    sets();
    multisets();
    unordered_sets();
    maps();
    multimaps();
    unordered_maps();

    Extra();
    return 0;
}



