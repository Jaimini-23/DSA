#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> pascalTriangle(int n, int r) {
    // Given row and column, return element      // using nCr
    // TC: O(r) and SC: O(1)
    // r = min(r,n-r);
    // long long res = 1;
    // for(int i=0; i<r; i++) {
    //     res = res * (n-i);
    //     res = res / (i+1);
    // }
    // cout << res;

    // print nth row
    // TC: O(n) and SC: O(1)
    // int ans = 1;
    // cout << ans << " ";
    // for(int i=1;i<n;i++) {
    //     ans = ans*(n-i);            // if 0-th Indexing : ans = ans * (n - i - 1)
    //     ans = ans/i;
    //     cout << ans <<" ";
    // }

    // print nth row pascal triangle
    //
    // vector<vector<int>> ans;
    // for(int i=1;i<=n;i++) {
    //     long long val = 1;
    //     vector<int> row;
    //     row.push_back(1);
    //     for(int col=1;col<i;col++) {
    //         val = val * (i - col);
    //         val = val / col;
    //         row.push_back(val);
    //     }
    //     ans.push_back(row);
    // }
    // return ans;
}


vector<int> majorityElement(vector<int> &arr, int n) {       // > n/3
    // Brute (TC: O(n^2)) and SC: O(1))
    // vector<int> ans;
    // for(int i=0;i<n;i++) {
    //     if(ans.size() == 0 || ans[0] != arr[i]) {
    //         int cnt = 0;
    //         for(int j=0;j<n;j++) {
    //             if(arr[j] == arr[i]) cnt ++;
    //         }
    //         if(cnt > n/3) ans.push_back(arr[i]);
    //     }
    //     else continue;
    //     if(ans.size() == 2) break;
    // }
    // return ans;

    // Better (TC: O(n)_avg and SC: O(n)_worst)
    // vector<int> ans;
    // unordered_map<int,int> mp;
    // for(int i=0;i<n;i++) {
    //     mp[arr[i]]++;
    // }
    // for(auto x: mp) {
    //     if(x.second > n/3) ans.push_back(x.first);
    // }
    // return ans;

    // Optimize (TC: O(2n) and SC: O(1))
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for(int i=0;i<n;i++) {
        if(cnt1 == 0 && el2 != arr[i]) {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2 == 0 && el1 != arr[i]) {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
        else cnt1--, cnt2--;
    }
    // verification of number of majority elements
    cnt1 = 0, cnt2 = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] == el1) cnt1++;
        if(arr[i] == el2) cnt2++;
    }
    if(cnt1 > n/3) ans.push_back(el1);
    if(cnt2 > n/3) ans.push_back(el2);
    return ans;
}


vector<vector<int>> threeSum(vector<int> &arr, int n, int r) {
    // Brute (TC: O(n^3)*log(no of unique triplets) and SC: O(2*(no of triplets))) 
    // set<vector<int>> st;
    // for(int i=0;i<n;i++) {
    //     for(int j=i+1;j<n;j++) {
    //         for(int k=j+1;k<n;k++) {
    //             if(arr[i] + arr[j] + arr[k] == r) {
    //                 vector<int> temp = {arr[i], arr[j], arr[k]};
    //                 sort(temp.begin(),temp.end());
    //                 st.insert(temp);
    //             }
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(),st.end());
    // return ans;

    // Better (TC: O(n^2 * log(m)) ans SC: O(n) + O(no of unique triplets)*2)
    // set<vector<int>> st;
    // for(int i=0;i<n;i++) {
    //     set<int> hashset;
    //     for(int j=i+1;j<n;j++) {
    //         int third = r - (arr[i] + arr[j]);
    //         if(hashset.find(third) != hashset.end()) {
    //             vector<int> temp = {arr[i], arr[j], third};
    //             sort(temp.begin(),temp.end());
    //             st.insert(temp);
    //         }
    //         hashset.insert(arr[j]);
    //     }
    // }
    // vector<vector<int>> ans(st.begin(),st.end());
    // return ans;

    // Optimize (TC: O(nlogn) + O(n*n) and SC: O(no of unique triplets)_ans)
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++) {
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < r) j++;
            else if(sum > r) k--;
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}


vector<vector<int>> fourSum(vector<int> &arr, int n, int r) {
    // Brute and Better solution is somehow simillar to threeSum
    // Optimize (TC: O(n^3) and SC: O(no of unique quads)_ans)
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++) {
        if(i>0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1;j<n;j++) {
            if(j != i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l) {
                long long sum = arr[i] + arr[j];    // instead 1LL * arr[i] + arr[j] + arr[k] + arr[l]
                sum += arr[k];                       // also to prevent integer overflow
                sum += arr[l];
                if(sum == r) {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while(k < l && arr[k] == arr[k-1]) k++;
                    while(k < l && arr[l] == arr[l+1]) l--;
                }
                else if(sum < r) k++;
                else l--;
            }
        }
    }
    return ans;
}


void count_subarray_with_xor_k(vector<int> &arr, int n, int r) {
    // Brute (TC: O(n^3) and SC: O(1))
    // int cnt = 0;
    // for(int i=0;i<n;i++) {
    //     for(int j=i;j<n;j++) {
    //         int xr = 0;
    //         for(int k=i;k<=j;k++) {
    //             xr ^= arr[k];
    //         }
    //         if(xr == r) cnt++;
    //     }
    // }
    // cout << cnt;

    // Better O(TC: O(n^2) ans SC: O(1))
    // int cnt = 0;
    // for(int i=0;i<n;i++) {
    //     int xr = 0;
    //     for(int j=i;j<n;j++) {
    //         xr ^= arr[j];
    //         if(xr == r) cnt++;
    //     }
    // }
    // cout << cnt;

    // Optimize (TC: O(n) and SC: O(n))
    // Subarray XOR = prefixXOR[R] ^ prefixXOR[L-1] (subarray L.....R)
    // Subarray XOR = k, prefixXOR[L-1] = prefixXOR[R] ^ k
    unordered_map<int,int> mp;
    mp[0] = 1;
    int xr = 0;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        xr ^= arr[i];
        cnt += mp[xr ^ r];
        mp[xr]++;
    }
    cout << cnt;
}


vector<vector<int>> merge_overlapping_intervals(vector<vector<int>> &arr, int n) {
    // TC: O(nlogn) + O(n) and SC: O(n)
    if (n == 0) return {};
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++) {
        if(ans.back()[1] >= arr[i][0]) {
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
        else {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}


void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2) {
    if(arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1],arr2[ind2]);
    }
}
void merge_two_sorted_arrays_without_extra_space(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    // two pointers
    // TC: O(min(n,m)_worst + O(nlogn) + O(mlogm) ans SC: O(1))
    // int left = n - 1;
    // int right = 0;
    // while(left >= 0 && right < m) {
    //     if(arr1[left] > arr2[right]) {
    //         swap(arr1[left], arr2[right]);
    //         left--, right++;
    //     }
    //     else break;
    // }
    // sort(arr1.begin(),arr1.end());
    // sort(arr2.begin(),arr2.end());

    // Another Optimal (gap method)
    // TC: O(log2(m+n)) * O(n+m) and SC: O(1)
    int len = n + m;
    int gap =  (len/2) + (len%2);        // GIF          // gap = (len + 1) / 2;
    while(gap > 0) {
        int left = 0;
        int right = left + gap;
        while(right < len) {
            // arr1 and arr2
            if(left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // arr2 and arr2
            else if(left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // arr1 and arr1
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if(gap == 1) break;
        gap = (gap/2) + (gap%2);              // gap = (gap + 1) / 2;
    }

}


void missing_repeating_number(vector<int> &arr, int n) {
    // Brute (TC: O(n^2) and SC: O(1))
    // int repeating = -1;
    // int missing = -1;
    // for(int i=1;i<=n;i++) {
    //     int cnt = 0;
    //     for(int j=0;j<n;j++) {
    //         if(arr[j] == i) cnt++;
    //     }
    //     if(cnt == 0) missing = i;
    //     else if(cnt == 2) repeating = i;

    //     if(missing != -1 && repeating != -1) {
    //         break;
    //     }
    // }
    // cout << "Missing: " << missing << endl;
    // cout << "Repeating: " << repeating;


    // Better (TC: O(2n) and SC: O(n))
    // int hash[n+1] = {0};
    // for(int i=0;i<n;i++) {
    //     hash[arr[i]]++;
    // }
    // int repeating = -1;
    // int missing = -1;
    // for(int i=1;i<=n;i++) {
    //     if(hash[i] == 2) repeating = i;
    //     else if(hash[i] == 0) missing = i;

    //     if(missing != -1 && repeating != -1) {
    //         break;
    //     }
    // }
    // cout << "Missing: " << missing << endl;
    // cout << "Repeating: " << repeating;


    // Optimize (By Maths)
    // TC: O(n) and SC: O(1)
    // S - Sn   --> x - y
    // S2 - S2n
    // long long Sn = (n * (n+1)) / 2;
    // long long S2n = (n * (n+1) * (2*n+1)) / 6;
    // long long S = 0, S2 = 0;
    // for(int i=0;i<n;i++) {
    //     S += arr[i];
    //     S2 += (long long)arr[i] * (long long)arr[i];
    // }
    // long long val1 = S - Sn;             // x - y
    // long long val2 = S2 - S2n;        // x^2 - y^2
    // val2 = val2 / val1;                        // x + y
    // long long x = (val1 + val2) / 2;
    // long long y = x - val1;
    // cout << x << " " << y;                 // return {(int)x, (int)y};


    // Another Optimal (XOR Method)
    int xr = 0;
    // XOR of array elements and numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xr ^= arr[i];
        xr ^= (i + 1);
    }
    // Find the rightmost set bit
    int number = xr & ~(xr - 1);

    int one = 0;
    int zero = 0;
    // Divide array elements into two groups
    for (int i = 0; i < n; i++) {
        if ((arr[i] & number) != 0)
            one ^= arr[i];
        else
            zero ^= arr[i];
    }
    // Divide numbers 1...n into two groups
    for (int i = 1; i <= n; i++) {
        if ((i & number) != 0)
            one ^= i;
        else
            zero ^= i;
    }
    // Find which one is repeating
    int cnt = 0;
    for (int x : arr) {
        if (x == one)
            cnt++;
    }

    if (cnt == 2)
        cout << one << " " << zero;     // repeating, missing
    else
        cout << zero << " " << one;
}


// Merge Sort algo 
// int merge(vector<int> &arr,int low,int mid,int high) {
//     vector<int> temp;
//     int left = low;
//     int right = mid+1;
//     int cnt = 0;
//     while(left <= mid && right <= high) {
//         if(arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else {
//             temp.push_back(arr[right]);
//             cnt += (mid - left + 1);
//             right++;
//         }
//     }

//     while(left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     for(int i=low;i<=high;i++) {
//         arr[i]=temp[i-low];
//     }
//     return cnt;
// }
// int ms(vector<int> &arr, int low, int high) {
//     int cnt = 0;
//     if (low >= high) return cnt;           // can also use low == high
//     int mid = low + (high - low) / 2;    
//     cnt += ms(arr,low,mid);
//     cnt += ms(arr,mid+1,high);

//     cnt += merge(arr,low,mid,high);
//     return cnt;
// }
void countInversions(vector<int> &arr, int n) {        // i > j, a[i] > a[j]
    // Brute (TC: O(n^2) and SC: O(1))
    // int cnt = 0;
    // for(int i=0;i<n;i++) {
    //     for(int j=i+1;j<n;j++) {
    //         if(arr[i] > arr[j]) cnt++;
    //     }
    // }
    // cout << cnt;

    // Optimize (TC: O(nlogn) and SC: O(n))
    // cout << ms(arr,0,n-1);
}


// Merge Sort algo 
void merge(vector<int> &arr,int low,int mid,int high) {
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++) {
        arr[i]=temp[i-low];
    }
}
int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for(int i=low;i<=mid;i++) {
        while(right <= high && arr[i] > 2LL * arr[right]) {
            right++;
        }
        cnt += right - (mid + 1);
    }
    return cnt;
}
int ms(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;           // can also use low == high
    int mid = low + (high - low) / 2;    
    cnt += ms(arr,low,mid);
    cnt += ms(arr,mid+1,high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr,low,mid,high);
    return cnt;
}
void reversePairs(vector<int> &arr, int n) {        // i < j, arr[i] > 2 * arr[j]
    // Brute solution is somehow simillar to countInversions
    // TC: O(n^2) ans SC: O(1)

    // Optimize
    // TC: O(2nlogn) ans SC: O(n)
    cout << ms(arr,0,n-1);
}


void maximumProductSubarray(vector<int> &arr, int n) {
    // Optimal (TC: O(n) and SC: O(1))
    int ans = INT_MIN;
    int pre = 1, suf = 1;
    for(int i=0; i<n; i++) {
        if(pre == 0) pre = 1;
        if(suf == 0) suf = 1;
        
        pre = pre * arr[i];
        suf = suf * arr[n - i - 1];
        ans = max(ans, max(pre, suf));
    }
    cout << ans;

    // Another Optimal
    // int maxProduct(vector<int>& nums) {
    //     int curMin = nums[0];
    //     int curMax = nums[0];
    //     int ans = nums[0];
    //     for(int  i=1;i<nums.size();i++) {
    //         if(nums[i] < 0) swap(curMin,curMax);
    //         curMax = max(nums[i], curMax*nums[i]);
    //         curMin = min(nums[i], curMin*nums[i]);

    //         ans = max(ans,curMax);
    //     }
    //     return ans;
    // }
}




int main() {
    int n ,r;
    cin >> n >> r;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    // vector<vector<int>> PT = pascalTriangle(n,r);
    // for(auto row: PT) {
    //     for(auto x: row) cout << x << " ";
    //     cout << endl;
    // }

    // vector<int> result = majorityElement(arr,n);
    // for(auto x: result) cout << x << " ";

    // vector<vector<int>> result = threeSum(arr,n,r);
    // for(auto x: result) {
    //     for(auto y: x) cout << y << " ";
    //     cout << endl;
    // }

    // vector<vector<int>> result = fourSum(arr,n,r);
    // for(auto x: result) {
    //     for(auto y: x) cout << y << " ";
    //     cout << endl;
    // }

    // count_subarray_with_xor_k(arr,n,r);

    // vector<vector<int>> intervals(n, vector<int>(2));
    // for(int i = 0; i < n; i++) {
    //     cin >> intervals[i][0] >> intervals[i][1];
    // }
    // vector<vector<int>> result = merge_overlapping_intervals(intervals,n);
    // for (auto it : result) {
    //     cout << it[0] << " " << it[1] << endl;
    // }

    // int n, m;
    // cin >> n >> m;
    // vector<int> arr1(n), arr2(m);
    // for(int i=0;i<n;i++) cin >> arr1[i];
    // for(int i=0;i<m;i++) cin >> arr2[i];
    // merge_two_sorted_arrays_without_extra_space(arr1,arr2,n,m);
    // for(int x: arr1) cout << x << " ";
    // cout << endl;
    // for(int y: arr2) cout << y << " ";

    // missing_repeating_number(arr,n);
    // countInversions(arr,n);
    // reversePairs(arr,n);


    return 0;
}




