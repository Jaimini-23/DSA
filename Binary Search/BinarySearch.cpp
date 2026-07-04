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


int minimum_in_rotated_sorted_array(vector<int> &arr, int n) {
    // TC: O(logn) and SC: O(1)
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // if the array is already fully sorted
        if(arr[low] <= arr[high]) {
            ans = min(ans,arr[low]);
            break;
        }
        // if left half is sorted
        if(arr[low] <= arr[mid]) {
            ans = min(ans,arr[low]);
            low = mid + 1;
        }
        // if right half is sorted
        else {
            ans = min(ans,arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}


int number_of_rotations_in_sorted_array(vector<int> &arr, int n) {
    // A rotated sorted array (with unique elements) is rotated by a count exactly equal to the index of the minimum element in the array   
    // eg. 3 4 5 1 2  -->  ans = 3
    // TC: O(logn) and SC: O(1)
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // if the array is already fully sorted
        if(arr[low] <= arr[high]) {
            if(arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            break;
        }
        // if left half is sorted
        if(arr[low] <= arr[mid]) {
            if(arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        // if right half is sorted
        else {
           if(arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
           }
            high = mid - 1;
        }
    }
    return index;

    // Handling Duplicates: apply the edge-case optimization from the Search in Rotated Sorted Array II pattern
    // When arr[low] == arr[mid] == arr[high], you cannot identify the sorted half.
    // You must trim the bounds (low++, high--) and keep a check on them before proceeding with normal binary search steps
}


int singleElement_in_sortedArray(vector<int> &arr, int n) {
    // Brute Force Approach (O(n) Time)
    // checks if an element's immediate neighbors are identical

    //  The Binary Search Optimization (O(log2_n) Time)
    // eg: 1 1 2 2 3 3 4 5 5 6 6  -->  ans = 4
    // Left Side of Single Element: Pairs follow an (Even Index, Odd Index) pattern
    // Right Side of Single Element: Pairs shift to an (Odd Index, Even Index) pattern

    if(n == 1) return arr[0];       // edge case, if arr has only one element
    // Edge Case: Check First and Last element manually to save boundary logic
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1;
    int high = n - 2;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])  return arr[mid];

        // Are we on the left half?
        if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) 
        || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}


int peakElement(vector<int> &arr, int n) {          // arr[i-1] < arr[i] > arr[i+1]
    // hypothetical minus infinity on both ends of the array. 
    // This ensures that even if the array is strictly increasing or decreasing, a peak will always exist
    // Multiple Peaks: If an array contains multiple peaks, returning any one of them is acceptable

    // Brute (TC: O(n) and SC: O(1))
    // for(int i=0; i<n; i++) {
    //     bool isGreaterLeft = (i == 0 || arr[i] > arr[i-1]);
    //     bool isGreaterRight = (i == n-1 || arr[i+1] < arr[i]);
    //     if(isGreaterLeft && isGreaterRight) {
    //         return i;
    //     }
    // }
    // return -1;

    // Optimal (TC: O(log2_n) and SC: O(1))
    // checking edge cases
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1;
    int high = n-2;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // If mid is a peak
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
        // If we are on an increasing slope, peak is to the right
        if(arr[mid] > arr[mid - 1]) low = mid + 1;
        // If we are on a decreasing slope, peak is to the left
        else high = mid - 1;
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
    // cout << search_element_in_rotated_sorted_array_2(arr,n,r);

    // cout << minimum_in_rotated_sorted_array(arr,n);
    // cout << number_of_rotations_in_sorted_array(arr,n);
    // cout << singleElement_in_sortedArray(arr,n);
    cout << peakElement(arr,n);

    return 0;
}




