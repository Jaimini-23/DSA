#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 1};
    int n = arr.size();
    int pivot = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1]) { // ascebding order found 
            pivot = i;
            break;
        }
    }

    if(pivot == -1) {
        reverse(arr.begin(),arr.end());
        return;
    }

    for(int i = n - 1; i >= pivot; i--) {
        if(arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    reverse(arr.begin() + pivot + 1, arr.end());
    return;
}

int main() {
    int k = 4;
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int cnt = 0;
    for(int i = 0;i<n;i++) {
        preSum += arr[i];
        int rem = preSum - k;
        cnt += mpp[rem];
        mpp[preSum]++;
    }
    cout << cnt;
}