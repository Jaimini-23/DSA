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


int cntSubarray(vector<int> &nums, int num) {
    int subarray = 1;
    long long cntNum = 0;
    for(int i=0; i<nums.size(); i++) {
        if(cntNum + nums[i] <= num) {
            cntNum += nums[i];
        }
        else {
            subarray++;
            cntNum = nums[i];
        }
    }
    return subarray;
}
int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    if(k > n) return -1;
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int subarray = cntSubarray(nums,mid);
        if(subarray > k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}


int median_of_two_sorted_arrays(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();
    if(n1 > n2) return median_of_two_sorted_arrays(b, a);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;         // total number of elements that should be present on left side of the partition
    int n = n1 + n2;

    while(low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1) {
            if(n % 2 == 1) return max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}


int Kth_element_of_two_sorted_arrays(vector<int> &a, vector<int> &b, int k) {
    int n1 = a.size();
    int n2 = b.size();
    if(n1 > n2) return Kth_element_of_two_sorted_arrays(b, a, k);
    int low = max(k - n2, 0), high = min(k, n1);
    int left = k;         // total number of elements that should be present on left side of the partition
    int n = n1 + n2;

    while(low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}


int lowerBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int row_with_max_1(vector<vector<int>> &arr, int n, int m) {          // if rows are sorted
    int cntMax = 0;
    int index = -1;
    for(int i=0; i<n; i++) {
        int cntOnes = m - lowerBound(arr[i], m, 1);
        if(cntOnes > cntMax) {
            cntMax = cntOnes;
            index = i;
        } 
    }
    return index;
}


bool searchMatrix(vector<vector<int>> &arr, int k) {   // if 2D matrix is sorted
    int n = arr.size();
    int m = arr[0].size();
    int low = 0, high = n * m - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        if(arr[row][col] == k) return true;
        else if(arr[row][col] < k) low = mid + 1;
        else high = mid - 1;
    }
    return false;
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




