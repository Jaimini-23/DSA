#include <bits/stdc++.h>
using namespace std;


int targetIndex(vector<int> &arr, int low, int high, int target) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return targetIndex(arr, mid + 1, high, target);
    else
        return targetIndex(arr, low, mid - 1, target);
}
int targetIndex_sortedArray(vector<int> &arr, int n, int r) {
    // TC: O(logn_with_base_2)
    // int low = 0;
    // int high = n - 1;
    // while(low <= high) {
    //     int mid = low + (high - low) / 2;
    //     if(arr[mid] == r) return mid;
    //     else if(arr[mid] < r) low = mid + 1;
    //     else high = mid - 1;
    // }
    // return -1;

    // By Recursion
    return targetIndex(arr, 0, n - 1, r);
}


int lowerBound(vector<int> &arr ,int n, int r) {       // smallest index such that arr[index] >= r
    // In C++ STL, lower_bound(arr.begin(), arr.end(), r) - arr.begin()
    // TC: O(logn)_with_base_2
    int low = 0;
    int high = n - 1;
    int ans = n;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] >= r) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}


int upperBound(vector<int> &arr ,int n, int r) {       // smallest index such that arr[index] > r
    // In C++ STL, upper_bound(arr.begin(), arr.end(), r) - arr.begin()
    // TC: O(logn)_with_base_2
    int low = 0;
    int high = n - 1;
    int ans = n;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] > r) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}


int searchInsertPosition(vector<int> &arr, int n, int r) {
    // This problem is identical to finding the Lower Bound
    int low = 0;
    int high = n - 1;
    int ans = n;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] >= r) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}


int findFloor(vector<int> &arr, int n, int r) {
    // Floor: The largest number in the array that is <= X
    // Ceil: The smallest number in the array that is >= X == Lower Bound
    // Lower Bound = First element >= x
    // Upper Bound = First element > x
    // Floor       = Largest element <= x
    // Ceil        = Smallest element >= x

    int low = 0;
    int high = n - 1;
    int ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] <= r) {
            ans = arr[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}


int findFirst(vector<int> &arr, int n, int r) {
    int low = 0;
    int high = n - 1;
    int first = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == r) {
            first = mid;
            high = mid - 1;          // look left
        }
        else if(arr[mid] < r) low = mid + 1;
        else high = mid - 1;
    }
    return first;
}
int findLast(vector<int> &arr, int n, int r) {
    int low = 0;
    int high = n - 1;
    int last = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == r) {
            last = mid;
            low = mid + 1;          // look right
        }
        else if(arr[mid] < r) low = mid + 1;
        else high = mid - 1;
    }
    return last;
}
void first_and_last_occurence_in_sorted_array(vector<int> &arr, int n, int r) {
    // Using Lower Bound and Upper Bound (last Occurence = Upper Bound - 1)
    // Edge Case Check: arr[lower_bound_index] != X

    // Approach 2: Raw Binary Search from Scratch
    cout << findFirst(arr,n,r) << " ";
    cout << findLast(arr,n,r);

    // TC: O(logn) and SC: O(1)
}


int Count_Occurrences_of_Number(vector<int> &arr, int n, int r) {
    // Total Occurrences = Last Occurrence - First Occurrence + 1
    // TC: O(logn) and SC: O(1)
    int first = findFirst(arr,n,r);
    if(first == -1) return 0;
    int last = findLast(arr,n,r);
    return (last - first) + 1;
}


int search_element_in_rotated_sorted_array(vector<int> &arr, int n, int r) {          // 4 5 6 1 2 3
    // If you split a rotated sorted array at any arbitrary index (mid), at least one of the halves (left half or right half) is guaranteed to be completely sorted
    // TC: O(logn) and SC: O(1)
    // does work for duplicates, what if arr[mid] == arr[low] == arr[high] and the either half may not be sorted
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = low + (high  - low) / 2;
        if(arr[mid] == r) return mid;

        // check if left half is sorted
        if(arr[low] <= arr[mid]) {
            if(arr[low] <= r && arr[mid] >= r) high = mid - 1;
            else low = mid + 1;
        }
        // otherwise, the right half is sorted
        else {
            if(arr[mid] <= r  && arr[high] >= r) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}


int search_element_in_rotated_sorted_array_2(vector<int> &arr, int n, int r) {
    // includes duplicates also like 4 5 4 4 4 4 
    // TC: Average = O(logn) and Worst = O(n/2) or O(n)
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = low + (high  - low) / 2;
        if(arr[mid] == r) return mid;
        // if arr[mid] != target, then arr[low] and arr[high] is also not then reduce the search area
        if(arr[mid] == arr[low] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        // check if left half is sorted
        if(arr[low] <= arr[mid]) {
            if(arr[low] <= r && arr[mid] >= r) high = mid - 1;
            else low = mid + 1;
        }
        // otherwise, the right half is sorted
        else {
            if(arr[mid] <= r  && arr[high] >= r) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}
















int main() {
    int n ,r;
    cin >> n >> r;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    // cout << targetIndex_sortedArray(arr,n,r);
    // cout << lowerBound(arr,n,r);
    // cout << upperBound(arr,n,r);
    // cout << findFloor(arr,n,r);
    // first_and_last_occurence_in_sorted_array(arr,n,r);
    // cout << Count_Occurrences_of_Number(arr,n,r);
    // cout << search_element_in_rotated_sorted_array(arr,n,r);
    cout << search_element_in_rotated_sorted_array_2(arr,n,r);
    return 0;
}




