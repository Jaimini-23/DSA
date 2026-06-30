#include <bits/stdc++.h>
using namespace std;


void largest_element(vector<int> arr, int n) {
    int largest = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i]>largest) largest=arr[i];
    }
    cout << largest;
    // can also do by sorting like merge sort and quick sort but that took time complexity O(nlogn) and this took O(n).
}


int secondLargest(vector<int> &arr, int n){
    int largest = arr[0];
    int slargest = INT_MIN;                             // assuming all are positive numbers
    for(int i=1;i<n;i++) {
        if(arr[i] > largest) {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > slargest && arr[i] < largest) {
            slargest = arr[i];
        }
    }
    return slargest;
}
int secondSmallest(vector<int> &arr, int n) {
    int smallest = arr [0];
    int ssmallest = INT_MAX;
    for(int i=1;i<n;i++) {
        if(arr[i] < smallest) {
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] > smallest && arr[i] < ssmallest) {
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}
void second(vector<int> &arr, int n) {
    int slargest = secondLargest(arr,n);
    int ssmallest = secondSmallest(arr,n);
    cout << ssmallest << " " << slargest;
    // these take time complexity O(n), so optimal solution.
}


bool sorted(vector<int> &arr, int n) {
    for(int i=1; i<n;i++) {
        if(arr[i] >= arr[i-1]);
        else return false;
    }
    return true;
    // TC: O(n)
}


int remove_duplicate_from_sorted(vector<int> &arr, int n) {
    //Brute (overall it tooks time complexity as O(nlogn + n))
    // also set looses previous order of arr
    // can also work for unsorted arr

    // set<int> st;
    // for(int i=0;i<n;i++) {
    //     st.insert(arr[i]);          // tooks time complexity as O(nlogn)
    // }
    // int index=0;
    // for(auto it: st) {              // tooks time complexity as O(n)
    //     arr[index] = it;
    //     index++;
    // }
    // arr.resize(index);           // to remove further elements from the arr
    // // or way with set
    // set<int> st(arr.begin(), arr.end());
    // arr.assign(st.begin(), st.end());


    // optimal (TC: O(n) and SC: O(1))
    // remove duplicates from sorted arr

    int i=0;
    for(int j=1;j<n;j++) {
        if(arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;               // number of unique elements
}


// Sorted array problem → two pointers, O(n) and O(1) space (best solution)
// if arr is not sorted then use set but if have to preserve the arr order of elements then use unordered set
// set removes duplicate and sorts (O(nlogn)) and unordered set removes duplicate and preserves insertion order (with extra vector)
// TC: O(n)average and SC: O(n)
vector<int> removeDuplicates(vector<int>& arr) {
    unordered_set<int> seen;
    vector<int> result;

    for (int x : arr) {
        if (seen.find(x) == seen.end()) {
            seen.insert(x);
            result.push_back(x);
        }
    }

    return result;
}


// The difference comes from the underlying data structure:
// set → usually implemented as a balanced binary search tree (Red-Black Tree)
// insert() → O(log n)
// find() → O(log n)
// elements are kept sorted
// unordered_set → implemented using a hash table
// insert() → O(1) average
// find() → O(1) average
// no ordering guarantee


vector<int> left_rotate_by_1(vector<int> &arr, int n) {
    int temp = arr[0];
    for(int i=1; i<n; i++) arr[i-1] = arr[i];
    arr[n-1] = temp;
    return arr;

    // if someone says, 'What is the space used in your algorithm?', then it becomes O(N) because you definitely are using this array...
    // But if someone says, 'what is the extra space (Auxiliary) that you're using?', then the extra space is O(1).
    //  Time Complexity (TC) is O(N)
}


// without STL for shifting/rotating you have to write reverse function also
void reverse(vector<int> &arr, int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    } 
}
vector<int> left_rotate_by_k(vector<int> &arr, int n, int k) {
    // k=k%n;    // after n rotates, arr will be the same as previous
    // if (k==0) return arr;
    // int temp[k];
    // for(int i=0;i<k;i++)  temp[i] = arr[i];
    // for(int i=0;i<n-k;i++)  arr[i] = arr[i+k];
    // for(int i=0;i<k;i++)  arr[n-k+i] = temp[i];
    // return arr;
    // TC: O(k) + O(n-k) + O(k) = O(n+k)
    // Extra space used: O(k)


    // optimized version
    k=k%n;
    if (k==0) return arr;
    reverse(arr.begin(),arr.begin()+k);            // without STL: reverse(arr,0,k-1)
    reverse(arr.begin()+k,arr.end());              // without STL: reverse(arr,k,n-1)
    reverse(arr.begin(),arr.end());                // without STL: reverse(arr,0,n-1)
    return arr;
    // TC: O(k) + O(n-k) + O(n) = O(2n);           // some extra TC from previous but less SC
    // Extra space used: O(1);
}


vector<int> right_rotate_by_k(vector<int> &arr, int n, int k) {
    k=k%n;
    if(k==0) return arr;
    reverse(arr.begin(),arr.begin()+(n-k));
    reverse(arr.begin()+(n-k),arr.end());
    reverse(arr.begin(),arr.end());
    return arr;
}


void move_zeroes_to_end(vector<int> &arr, int n) {
    // Brute (TC: O(n) + O(temp.size()) + O(n - temp.size()) = O(2n))
    // vector<int> temp;
    // for(int i=0;i<n;i++) {
    //     if(arr[i] != 0) temp.push_back(arr[i]);
    // }
    // if(temp == arr) return;
    // for(int i=0;i<temp.size();i++) arr[i] = temp[i];
    // for(int i=temp.size();i<n;i++) arr[i] = 0;


    // optimize (O(n) time and O(1) space)
    int i=0;
    for(int j=0;j<n;j++) {
        if(arr[j] != 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }

    }

}


int linearSearch(vector<int> &arr, int n, int num) {
    for(int i=0;i<n;i++) {
        if(arr[i] == num) return i;
    }
    return -1;
}


vector<int> union_sorted_arr(vector<int> &arr1, vector<int> &arr2, int n1, int n2) {
    // Brute (TC = O((n1 + n2) log k) and SC = O(k)) where k is the size of the set
    // set<int> st;       // removes duplicate and stores unique elements and also works for non sorted arr's but result will be sorted arr
    // for(int i=0;i<n1;i++) st.insert(arr1[i]);
    // for(int i=0;i<n2;i++) st.insert(arr2[i]);
    // vector<int> uni;
    // for(auto it : st) {
    //     uni.push_back(it);
    // }
    // return uni;


    // optimize (TC: O(n1+n2) and SC: (O(1), ignoring the output arr), (O(n1+n2),including the output vector))
    int i=0, j=0;
    vector<int> uni;
    while(i<n1 && j<n2) {
        if(arr1[i] <= arr2[j]) {
            if(uni.size() == 0 || uni.back() != arr1[i]) {
                uni.push_back(arr1[i]);
            }
            i++;
        }
        else {
            if(uni.size() == 0 || uni.back() != arr2[j]) {
                uni.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i<n1) {
        if(uni.size() == 0 || uni.back() != arr1[i]) {
            uni.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2) {
        if(uni.size() == 0 || uni.back() != arr2[j]) {
            uni.push_back(arr2[j]);
        }
        j++;
    }
    return uni;
}


vector<int> intersection_sorted_arr(vector<int> &arr1, vector<int> &arr2, int n1, int n2) {
    // Brute (TC: O(n1*n2) and SC: O(n2))
    // vector<int> inter;
    // int vis[n2] = {0};
    // for(int i=0;i<n1;i++) {
    //     for(int j=0;j<n2;j++) {
    //         if(arr1[i] == arr2[j] && vis[j] == 0) {
    //             inter.push_back(arr1[i]);
    //             vis[j] = 1;
    //             break;
    //         }
    //         if(arr2[j] > arr1[i]) break;
    //     }
    // }
    // return inter;


    // optimize (TC: O(n1 + n2) and SC: O(1))
    int i=0,j=0;
    vector<int> inter;
    while(i<n1 && j<n2) {
        if(arr1[i] < arr2[j]) i++;
        else if(arr2[j] < arr1[i]) j++;
        else {
            inter.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return inter;
}


void missingNumber(vector<int> &arr, int n) {
    // Brute (TC: O(n^2) and SC: O(1))
    // for(int i=1;i<=n;i++) {
    //     int flag = 0;
    //     for(int j=0;j<n-1;j++) {         // n-1 because one element is missing 
    //         if(arr[j] == i) {            // so for eg. arr = [1,2,4,5] valid indices are 0,1,2,3
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if(flag == 0) {
    //         cout << i;
    //         return;
    //     }
    // }


    // Better (TC: O(n) + O(n) = O(2n) and SC: O(n))
    // int hash[n+1] = {0};
    // for(int i=0;i<n-1;i++) hash[arr[i]] = 1;
    // for(int i=1;i<n+1;i++) {
    //     if(hash[i] == 0) {
    //         cout << i;
    //         return;
    //     }
    // }


    // optimize (TC: O(n) and SC: O(1))
    // M1 (sum)
    // int sum = n*((n+1)/2);
    // int actual_sum=0;
    // for(int x : arr) {
    //     actual_sum += x;
    // }
    // cout << sum - actual_sum;

    // M2 (XOR)
    int xor1=0, xor2=0;                        // 1 2 4 5
    for(int i=1;i<=n;i++) xor1 ^= i;           // 1^2^3^4^5
    for(int x: arr) xor2 ^= x;                // 1^2^4^5
    cout << (xor1 ^ xor2);                    // (1^2^3^4^5)^(1^2^4^5)          // 3
}


void max_consecutive_ones(vector<int> &arr, int n) {
    int maxi=0,cnt=0;
    for(int i=0;i<n;i++) {
        if(arr[i] == 1) {
            cnt += 1;
            maxi = max(maxi,cnt);
        }
        else cnt = 0;
    }
    cout << maxi;
}


void number_that_apppears_ones_others_twice(vector<int> &arr, int n) {
    // Brute (TC: O(n^2) and SC: O(1)
    // for(int i=0;i<n;i++) {
    //     int cnt = 0;
    //     int num = arr[i];
    //     for(int j=0;j<n;j++) {
    //         if(arr[j] == num) cnt++;
    //     }
    //     if(cnt == 1) {
    //         cout << num;
    //         return;
    //     }
    // }


    // Better (TC: O(2n) and SC: O(max(arr)))
    // int maxi = *max_element(arr.begin(), arr.end());
    // int hash[maxi + 1] = {0};
    // for(int i=0;i<n;i++) hash[arr[i]]++;
    // for(int i=0;i <= maxi;i++) {
    //     if(hash[i] == 1) {
    //         cout << i;
    //         return;
    //     }

    // }

    // Better to use hash map then hash array
    // unordered_map<long long,int> mp;
    // for(int x : arr)
    // mp[x]++;
    // for(auto it : mp) {
    //     if(it.second == 1) {
    //         cout << it.first;
    //         return;
    //     }
    // }


    // optimize (TC: O(n) and SC: O(1))
    int xorNums = 0;
    for(int it: arr) xorNums ^= it;
    cout << xorNums;
}


void longest_subarray_with_sum_k_positive(vector<int> &arr, int n, int k) {
    // // Brute (TC: O(n^2) and SC: O(1))
    // int len = 0;
    // for(int i=0;i<n;i++) {
    //     int s=0;
    //     for(int j=i;j<n;j++) {
    //         s += arr[j];
    //         if(s == k) len = max(len,j-i+1);
    //     }
    // }
    // cout << len;


    // Better (TC: O(n) with unordered map and O(nlogn) with ordered map and SC: O(n))
    // map<long long,int> preSumMap;
    // long long sum = 0;
    // int maxlen = 0;
    // for(int i=0;i<arr.size();i++) {
    //     sum += arr[i];
    //     if(sum == k) maxlen = max(maxlen,i+1);

    //     long long rem = sum - k;
    //     if(preSumMap.find(rem) != preSumMap.end()) {
    //         int len = i - preSumMap[rem];
    //         maxlen = max(maxlen,len);
    //     }

    //     if(preSumMap.find(sum) == preSumMap.end()) {
    //         preSumMap[sum] = i;
    //     }
    // }
    // cout << maxlen;


    // optimize (TC: O(2n) because inner while does not run always and SC: O(1))
    int i=0,j=0;
    long long sum = arr[0];
    int maxlen = 0;
    while(j<n) {
        while(i <= j && sum > k) {
            sum -= arr[i];
            i++;
        }
        if(sum == k) maxlen = max(maxlen,j-i+1);
        j++;
        if(j<n) sum += arr[j];
    }
    cout << maxlen;
}


void longest_subarray_with_sum_k_positive_negative(vector<int> &arr, int n, int k) {
    // optimize (TC: O(2n) because inner while does not run always and SC: O(1))
    map<long long,int> preSumMap;
    long long sum = 0;
    int maxlen = 0;
    for(int i=0;i<arr.size();i++) {
        sum += arr[i];
        if(sum == k) maxlen = max(maxlen,i+1);

        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxlen = max(maxlen,len);
        }

        if(preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    cout << maxlen;
}




int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)  cin >> arr[i];
    
    // largest_element(arr,n);
    // second(arr,n);

    // int result = sorted(arr,n);
    // cout << result;

    // int result = remove_duplicate_from_sorted(arr,n);
    // cout << result;

    // vector<int> result = removeDuplicates(arr);
    // for(auto x: result) cout << x << " ";

    // vector<int> result = left_rotate_by_1(arr,n);
    // for(auto x: result) cout << x << " ";

    // int k;
    // cin >> k;
    // vector<int> result = left_rotate_by_k(arr,n,k);
    // for(auto x: result) cout << x << " ";

    // vector<int> result = right_rotate_by_k(arr,n,k);
    // for(auto x: result) cout << x << " ";

    // move_zeroes_to_end(arr,n);

    // int num;
    // cin >> num;
    // int result = linearSearch(arr,n,num);
    // cout << result;

    // int n1,n2;
    // cin >> n1 >> n2;
    // vector<int> arr1(n1);
    // for(int i=0;i<n1;i++)  cin >> arr1[i];
    // vector<int> arr2(n2);
    // for(int i=0;i<n2;i++)  cin >> arr2[i];
    // vector<int> result_union = union_sorted_arr(arr1,arr2,n1,n2);
    // for(auto it : result_union) cout << it << " ";
    // cout << endl;
    // vector<int> result_intersection = intersection_sorted_arr(arr1,arr2,n1,n2);
    // for(auto it : result_intersection) cout << it << " ";

    // missingNumber(arr,n);
    // max_consecutive_ones(arr,n);
    // number_that_apppears_ones_others_twice
    
    int k;
    cin >> k;
    // longest_subarray_with_sum_k_positive(arr,n,k);
    longest_subarray_with_sum_k_positive_negative(arr,n,k);


    return 0;
}

