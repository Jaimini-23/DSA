#include <bits/stdc++.h>
using namespace std;


void selection_sort(int arr[],int n) {
    // select minimum and swap
    for(int i=0;i<n-1;i++) {              // we only go till n-2 steps (from zero) because last element is not need to be check
        int mini=i;
        for(int j=i;j<n;j++) {             // to find minimum value index across array
            if(arr[j] < arr[mini]) mini=j;
        }
        swap(arr[i],arr[mini]);
    }
    // Its time complexity (worst,best,average) is O(n^2)
}


void bubble_sort(int arr[],int n) {
    // push the max to the last by adjacent swaps
    for(int i=0;i<n;i++) {
        int didswap=0;
        for(int j=0;j<n-i;j++) {         // n-i because no need check the last elements, as they are getting sorted as i increases
            if(arr[j+1]<arr[j]) {
                swap(arr[j+1],arr[j]);
                didswap=1;
            }
        }
        if(didswap==0) break;          // for already sorted array, no need to run loops multiple times and why to increase the time complexity
    }
    // Its time complexity (worst (reverse sorted array),average) is O(n^2) but for already sorted array time complexity (best) will be O(n)
}


void insertion_sort(int arr[],int n) {
    // takes an element and place it in its correct position
    for(int i=0;i<n;i++) {
        int j=i;
        while(j>0 && arr[j-1]>arr[j]) {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    // eg: 13 46 24 52 20 9
    // 13 46 24 52 20 9
    // 13 24 46 52 20 9
    // 13 24 46 52 20 9
    // 13 20 24 46 52 9
    // 9 13 20 24 46 52
    // Its time complexity (worst (reverse sorted array),average) is O(n^2) but for already sorted array time complexity (best) will be O(n)
}

// Merge Sort
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
void ms(vector<int> &arr, int low, int high) {
    if (low >= high) return;           // can also use low == high
    int mid = low + (high - low) / 2;    
    ms(arr,low,mid);
    ms(arr,mid+1,high);

    merge(arr,low,mid,high);
}
void merge_sort(vector<int> &arr,int n) {
    // Merge Sort is considered an optimized sorting algorithm because it uses the Divide, Conquer and merge technique and guarantees O(nlogn)(with base 2 because each time array is divided into 2 subarray) time complexity in the best, average, and worst cases,
    // making it much more efficient than O(n^2) sorting algorithms for large datasets. 
    // space complexity is O(n) and time complexity is O(nlogn)(with base 2 because each time array is divided into 2 subarray)
    // Merge Sort is not the most optimized sorting algorithm overall. Algorithms like Quick Sort (average O(nlogn), in-place) and Heap Sort (O(nlogn), O(1) extra space) are also important
    ms(arr,0,n-1);
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j) {
        while(arr[i] <= pivot && i <= high -1) {
            i++;
        }

        while(arr[j] > pivot && j >= low+1) {
            j--;
        }

        if (i<j) swap(arr[i], arr[j]);        
    }
    swap(arr[low], arr[j]);
    return j;
}
void quick_sort(vector<int> &arr, int low, int high) {
    // Unlike Merge Sort, Quick Sort does not need an extra temporary array, which is why it is considered an in-place sorting algorithm
    // Choose a Pivot: First element, Last element, Middle element, Random element...
    // Put all elements smaller than the pivot on the left and Put all elements greater than the pivot on the right. Pivot reaches its correct sorted position.

    // 4 6 2 5 7 9 1 3
    // 2 1 3 | 4 | 6 5 7 9  // Now 4 is in its final sorted position.
    // same further steps till all become sorted.

    if(low<high) {
        int pIndex = partition(arr,low,high);
        quick_sort(arr,low,pIndex-1);
        quick_sort(arr,pIndex+1,high);
    }

    // time complexity is O(nlogn) for best and average case and O(n^2) for worst case (Occurs when the pivot is always the smallest or largest element)
    // space complexity is O(logn) for best and average case (still uses recursive function calls so not O(1)) and O(n) for worst case
    // auxiliary space excluding the recursion stack: O(1)
}



int main() {
    int n;
    cin >> n;
    // int arr[n];
    // for(int i=0;i<n;i++) cin >> arr[i];

    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr,n);

    vector<int> arr={13,46,24,52,20,9};
    // merge_sort(arr,6);
    // for(auto it : arr) cout << it << " ";

    quick_sort(arr,0,arr.size()-1);
    for(auto it : arr) cout << it << " ";

    // for(int i=0;i<n;i++) cout << arr[i] << " ";
    return 0;
}




