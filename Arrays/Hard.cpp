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








int main() {
    int n ,r;
    cin >> n >> r;
    // vector<int> arr(n);
    // for(int i=0;i<n;i++) cin >> arr[i];

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

    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<vector<int>> result = merge_overlapping_intervals(intervals,n);
    for (auto it : result) {
        cout << it[0] << " " << it[1] << endl;
    }










    return 0;
}



