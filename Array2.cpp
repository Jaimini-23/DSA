#include <bits/stdc++.h>
using namespace std;


void isTwoSum(vector<int> &arr,int n,int k) {
    // Brute (TC: O(n^2) and SC: O(1))
    // for(int i=0;i<n;i++) {
    //     for(int j=i+1;j<n;j++) {
    //         if(arr[i] + arr[j] == k) {
    //             cout << "Yes";
    //             return;
    //         }
    //     }
    // }
    // cout << "No";


    // Better/optimize (TC: O(n)_average for unordered map and O(nlogn) for ordered map and SC: O(n))
    map<int,int> mp;    // value -> index
    for(int i=0;i<n;i++) {
        int rem = k - arr[i];
        if(mp.find(rem) != mp.end()) {
            cout << "Yes";
            return;
        }
        mp[arr[i]] = i;
    }
    cout << "No";


    // reducing the SC but distorted the array
    // TC: O(n) + O(nlogn)_dueToSorting and SC: O(1)
    // int left=0,right=n-1;
    // sort(arr.begin(),arr.end());
    // while(left < right) {
    //     int sum = arr[left] + arr[right];
    //     if(sum == k) {
    //         cout << "Yes";
    //         return;
    //     }
    //     else if(sum < k) left++;
    //     else right--;
    // }
    // cout << "No";
}


void twoSum(vector<int> &arr, int n, int k) {
    // want indecies
    // optimize (TC: O(n)_average for unordered map and O(nlogn) for ordered map and SC: O(n))
    map<int,int> mp;    // value -> index
    for(int i=0;i<n;i++) {
        int rem = k - arr[i];
        if(mp.find(rem) != mp.end()) {
            cout << mp[rem] << " " << i;
            return;
        }
        mp[arr[i]] = i;
    }
    cout << -1 << " " << -1;
}


vector<int> sort_array_of_Zeroes_ones_twoes(vector<int> &arr, int n) {
    // Brute (Use Of Merge Sort (TC: O(nlogn) and SC: O(n)))

    // Better (TC: O(2n) and SC: O(1))
    // int cnt0 = 0;
    // int cnt1 = 0;
    // int cnt2 = 0;
    // for(int i=0;i<n;i++) {
    //     if(arr[i] == 0) cnt0++;
    //     if(arr[i] == 1) cnt1++;
    //     if(arr[i] == 2) cnt2++;
    // }
    // for(int i=0;i<cnt0;i++) arr[i] = 0;
    // for(int i = cnt0; i < cnt0+cnt1; i++) arr[i] = 1;
    // for(int i = cnt0+cnt1; i<n; i++) arr[i] = 2;
    // return arr;

    
    // optimize (Dutch National Flag Algo)_three_pointers
    // TC: O(n) and SC: O(1)
    // 0 .... low-1        ->    0
    // low-1 .... mid-1    ->    1
    // mid .... high       ->    0/1/2
    // high+1 .... n-1     ->    2
    int low = 0, mid = 0, high = n-1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return arr;
}


void majority_element(vector<int> &arr, int n) {
    // Brute (TC: O(n^2) and SC: O(1))
    // for(int i=0;i<n;i++) {
    //     int cnt = 0;
    //     for(int j=0;j<n;j++) {
    //         if(arr[j] == arr[i]) cnt++;
    //     }
    //     if(cnt > n/2) {
    //         cout << i;
    //         return;
    //     }
    // }
    // cout << -1;


    // // Better (TC: O(n) + O(nlogn) and SC: O(n))
    // map<int,int> mp;
    // for(int i=0;i<n;i++) mp[arr[i]]++;
    // for(auto it: mp) {
    //     if(it.second > n/2) {
    //         cout << it.first;
    //         return;
    //     }
    // }
    // cout << -1;


    // optimize (Moore's Voting algo)
    // TC: O(n)_algo + O(n)_verify and SC: O(1)
    int cnt = 0;
    int el;
    for(int i=0;i<n;i++) {
        if(cnt == 0) {
            cnt = 1;
            el = arr[i];
        }
        else if(arr[i] == el) cnt++;
        else cnt--;
    }
    // verifying step (if majority element does not exist)
    int cnt1 = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] == el) cnt1++;
    }
    if(cnt1 > n/2) {
        cout << el;
        return;
    }
    cout << -1;
    return;
}


void subarray_with_max_sum(vector<int> &arr, int n) {
    // Brute (TC: O(n^3) and SC: O(1))
    // int maxi = INT_MIN;
    // for(int i=0;i<n;i++) {
    //     for(int j=i;j<n;j++) {
    //         int sum = 0;
    //         for(int k=i;k<=j;k++) {
    //             sum += arr[k];
    //         }
    //         maxi = max(maxi,sum);
    //     }
    // }
    // cout << maxi;


    // Better (TC: O(n^2) and SC: O(1))
    // int maxi = INT_MIN;
    // for(int i=0;i<n;i++) {
    //     int sum = 0;
    //     for(int j=i;j<n;j++) {
    //         sum += arr[j];
    //         maxi = max(maxi,sum);
    //     }
    // }
    // cout << maxi;


    // optimize (Kadane's Algo)
    // TC: O(n) and SC: O(1)
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    if(maxi < 0) maxi = 0;     // if empty subarray is included, making sure that if all elements is negative thus empty subarray should return
    cout << maxi;
    return;
}


pair<int,int> print_subarray_with_max_sum(vector<int> &arr, int n) {
    int maxi = INT_MIN;
    int sum = 0;
    int start=0,end=0;
    int tempstart=0;

    for(int i=0;i<n;i++) {
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
            start = tempstart;
            end = i;
        }
        if(sum < 0) {
            sum = 0;
            tempstart = i+1;
        }
    }
    return {start,end};
}


void Buy_sell_stocks_max_profit(vector<int> &arr,int n) {
    // Dynamic Programming
    int mini = arr[0];
    int maxProfit = 0;
    for(int i=0;i<n;i++) {
        int cost = arr[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, arr[i]);
    }
    cout << maxProfit;
    return;
}


vector<int> rearrange_alternative_by_sign(vector<int> &arr, int n) {         // 3 1 -2 -5 2 -4 to 3 -2 1 -5 2 -4     // n is alwaus even
    // Brute (TC: O(n + n/2) and SC: O(n))
    // vector<int> pos,neg;
    // for(int i=0;i<n;i++) {
    //     if(arr[i] > 0) pos.push_back(arr[i]);
    //     else neg.push_back(arr[i]);
    // }
    // for(int i=0;i<n/2;i++) {
    //     arr[2*i] = pos[i];
    //     arr[2*i+1] = neg[i]; 
    // }
    // return arr;


    // optimize (TC: O(n) and SC: O(n)_ans)
    vector<int> ans(n, 0);
    int posIndex = 0, negIndex = 1;
    for(int i=0;i<n;i++) {
        if(arr[i] < 0) {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
        else {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    return ans;

    // if positives and negatives are not equal, use brute solution and make pos and neg array and combine them
}


vector<int> nextPermutation(vector<int> &arr, int n) {
    // In c++, we can use STL ( next_permutation() and prev_permutation() )
    // Optimize (TC: O(3n) and SC: O(1))
    int ind = -1;              // pivot = 1
    for(int i=n-2;i>=0;i--) {        // checking each pair is in asscending or not 
        if(arr[i] < arr[i+1]) {
            ind = i;                  // if in asscending, assign ind (pivot) as i
            break;
        }
    }

    if(ind == -1) {                // this mean provided array is in descending order
        reverse(arr.begin(),arr.end());      // reverse and give its smallest as next permutation
        return arr;
    }


    for(int i=n-1;i>ind;i--) {              // to get the next highest/next permutation
        if(arr[i] > arr[ind]) {
            swap(arr[i],arr[ind]);
            break;
        }
    }

    reverse(arr.begin() + ind + 1, arr.end());        // at ahead of pivot, we reverse the numbers so that we can get the just next higher number/next permutation
    return arr;
}


vector<int> leaders(vector<int> &arr, int n) {       // everything on the right of number should be smaller
    // Brute (TC: O(n^2))
    // vector<int> ans;
    // for(int i=0;i<n;i++) {
    //     bool leader = true;
    //     for(int j=i+1;j<n;j++) {
    //         if(arr[j] > arr[i]) {
    //             leader = false;
    //             break;
    //         }
    //     }
    //     if(leader == true) ans.push_back(arr[i]);
    // }
    // return ans;


    // optimize (TC: O(n) and SC: O(n)_ans + O(1)_toSolve)
    int maxi = INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>-1;i--) {
        if(arr[i] > maxi) {
            ans.push_back(arr[i]);
            maxi = max(maxi, arr[i]);
        }
    }
    return ans;
}


void longest_successive_elements(vector<int> &arr, int n) {
    // if(n == 0) {
    //     cout << 0;
    //     return;
    // }

    // sort(arr.begin(),arr.end());
    // int lastSmaller = INT_MIN;
    // int cnt = 0;
    // int longest = 1;

    // for(int i=0;i<n;i++) {
    //     if(arr[i] - 1 == lastSmaller) {
    //         cnt++;
    //         lastSmaller = arr[i];
    //     }
    //     else if(lastSmaller != arr[i]) {
    //         cnt = 1;
    //         lastSmaller = arr[i];
    //     }
    //     longest = max(longest, cnt);
    // }
    // cout << longest;
    // return;


    // optimal (TC: O(n) + O(2n)_approx (assuming that unordered set took O(1) tc not like worst case O(n)) and SC: O(n))
    if(n == 0) {
        cout << 0;
        return;
    }
    int longest = 1;
    unordered_set<int> st;
    for(int i=0;i<n;i++) {
        st.insert(arr[i]);
    }
    for(auto it: st) {
        if(st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()) {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    cout << longest;
    return;
}


void markRow(vector<vector<int>> &arr, int i, int m) {
    for(int k=0;k<m;k++) {
        if(arr[i][k] != 0) arr[i][k] = -1;
    }
}
void markColumn(vector<vector<int>> &arr, int j, int n) {
    for(int k=0;k<n;k++) {
        if(arr[k][j] != 0) arr[k][j] = -1;
    }
}
void setMatrixZeroes(vector<vector<int>> &arr, int n, int m) {
    // Brute (TC: O(n*m) * O(n+m) + O(n*m))
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         if(arr[i][j] == 0) {
    //             markRow(arr,i,m);
    //             markColumn(arr,j,n);
    //         }
    //     }
    // }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         if(arr[i][j] == -1) arr[i][j] = 0;
    //     }
    // }


    // Better (TC: O(2*n*m) and SC: O(n) + O(m))
    // int col[m] = {0};
    // int row[n] = {0};
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         if(arr[i][j] == 0) {
    //             row[i] = 1;
    //             col[j] = 1;
    //         }
    //     }
    // }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         if(row[i] == 1 || col[j] == 1) arr[i][j] = 0;
    //     }
    // }


    // Optimize (TC: O(2*n*m) and SC: O(1))
    // int col[m] = {0}  ->  arr[0][..]
    // int row[n] = {0}  ->  arr[..][0]
    int col0 = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 0) {
                // mark the i-th row
                arr[i][0] = 0;
                // mark the j-th col
                if(j != 0) arr[0][j] = 0;
                else col0 = 0;
            }
        }
    }
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            // check for row and col
            if(arr[0][j] == 0 || arr[i][0] == 0) arr[i][j] = 0;
        }
    }
    if(arr[0][0] == 0) {
        for(int j=0;j<m;j++) arr[0][j] = 0;
    }
    if(col0 == 0) {
        for(int i=0;i<n;i++) arr[i][0] = 0;
    }
}


void rotate_matrix_by_90(vector<vector<int>> &arr, int n) {
    // 1 2 3  ->  // 1 4 7  ->  // 7 4 1
    // 4 5 6      // 2 5 8      // 8 5 2
    // 7 8 9      // 3 6 9      // 9 6 3
    // transpose
    for(int i=0;i<=n-2;i++) {       // in last row, nothing will remain to swap, that's why loop till n-2
        for(int j=i+1;j<n;j++) {                // we are going for upper diagonal elements and swapping them with the lower diagonal elements
            swap(arr[i][j], arr[j][i]);
        }
    }
    // reverse
    for(int i=0;i<n;i++) {
        reverse(arr[i].begin(), arr[i].end());
    }
    // TC: O(n^2)_approx and SC: O(1)
}


vector<int> spiralMatrix(vector<vector<int>> &arr, int n, int m) {
    // TC: O(n*m) and SC: O(1)_excluding_ans
    int left = 0, right = m-1;
    int top = 0, bottom = n-1;
    vector<int> ans;

    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++) {
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return ans;
}


void no_of_subarrays_with_sum_k(vector<int> &arr, int n, int k) {
    // Better (TC: O(n^2) and SC: O(1))
    // int cnt = 0;
    // for(int i=0;i<n;i++) {
    //     int sum = 0;
    //     for(int j=i;j<n;j++) {
    //         sum += arr[j];
    //         if(sum == k) cnt++;
    //     }
    // }
    // cout << cnt;

    // optimize (TC: O(n) and SC: O(n))
    unordered_map<int, int> mp;
    int preSum = 0;
    int cnt = 0;
    mp[0] = 1;
    for(int i=0;i<n;i++) {
        preSum += arr[i];
        int rem = preSum - k;
        cnt += mp[rem];
        mp[preSum]++;
    }
    cout << cnt;
}




int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    // isTwoSum(arr,n,k);
    // twoSum(arr,n,k);

    // vector<int> result = sort_array_of_Zeroes_ones_twoes(arr,n);
    // for(int x: result) cout << x;

    // majority_element(arr,n);
    // subarray_with_max_sum(arr,n);
    // auto p = print_subarray_with_max_sum(arr,n);
    // for(int i = p.first; i <= p.second; i++)  cout << arr[i] << " ";

    // Buy_sell_stocks_max_profit(arr,n);
    // vector<int> result = rearrange_alternative_by_sign(arr,n);
    // for(auto x: result) cout << x << " "; 

    // vector<int> result = nextPermutation(arr,n);
    // for(auto x: result) cout << x << " "; 

    // vector<int> result = leaders(arr,n);
    // for(auto x: result) cout << x << " "; 

    // longest_successive_elements(arr,n);

    // int n,m;
    // cin >> n >> m;
    // vector<vector<int>> arr(n,vector<int>(m));
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cin >> arr[i][j];
    //     }
    // }
    // setMatrixZeroes(arr,n,m);
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int n;
    // cin >> n;
    // vector<vector<int>> arr(n,vector<int>(n));
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         cin >> arr[i][j];
    //     }
    // }
    // rotate_matrix_by_90(arr,n);
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    no_of_subarrays_with_sum_k(arr,n,k);


    return 0;
}




