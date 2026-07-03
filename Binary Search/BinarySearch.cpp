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























int main() {
    int n ,r;
    cin >> n >> r;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << targetIndex_sortedArray(arr,n,r);
    return 0;
}




