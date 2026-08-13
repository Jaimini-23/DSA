#include <bits/stdc++.h>
using namespace std;


int findDays(vector<int> &weight, int cap) {
    int days = 1, load = 0;
    for(int i=0; i<weight.size(); i++) {
        if(load + weight[i] > cap) {
            days++;
            load = weight[i];
        }
        else {
            load += weight[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &weight, int n, int days) {
    // TC: O(n × log(sum(weights)−max(weights))) and SC: O(1)

    int low = *max_element(weight.begin(),weight.end());
    int high = accumulate(weight.begin(),weight.end(),0LL);

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int numberOfDays = findDays(weight, mid);
        if(numberOfDays <= days) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}


int kthMissingNumber(vector<int> &arr, int n, int k) {
    // Brute (TC: O(n) and SC: O(1)) 
    // for(int i=0; i<n; i++) {
    //     if(arr[i] <= k) k++;
    //     else break;
    // }
    // return k;

    // optimal (TC: O(logn) and SC: O(1))
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k) low = mid + 1;
        else high = mid - 1;
    }
    return k + high + 1;          // or return low + k;
}


bool canWePlace(vector<int> &arr, int dist, int cows) {
    int cntCows = 1, last = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] - last >= dist) {
            cntCows++;
            last = arr[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &arr, int n, int k) {        // (minmum distance between cows) is maximum
    // optimized (TC: O(n log n + n log(maxDistance))) and SC: O(1))
    sort(arr.begin(),arr.end());
    int low = 1, high = arr[n - 1] - arr[0];
    while(low <= high) {
        int mid = (low + high) / 2;
        if(canWePlace(arr, mid, k) == true) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}


int cntStudents(vector<int> &arr, int pages) {
    int students = 1;
    long long pagesStudents = 0;
    for(int i=0; i<arr.size(); i++) {
        if(pagesStudents + arr[i] <= pages) {
            pagesStudents += arr[i];
        }
        else {
            students++;
            pagesStudents = arr[i];
        }
    }
    return students;
}
int allocateBooks(vector<int> &arr, int n, int k) {             // maximum no of pages assigned to a student is minimum
    // TC: O(n logn(sum of pages)) SC: O(1)
    if(k > n) return -1;  // student more and books less
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int students = cntStudents(arr,mid);
        if(students > k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}









int main() {
    int n ,r;
    cin >> n >> r;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    // cout << leastWeightCapacity(arr,n,r);
    cout << kthMissingNumber(arr,n,r);
    return 0;
}




