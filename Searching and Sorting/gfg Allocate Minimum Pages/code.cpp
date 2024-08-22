#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
   
   bool isFeasible(int arr[], int n, int m, long long maxPages) {
    int studentCount = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) {
            return false;  
        }

        if (currentSum + arr[i] > maxPages) {
            studentCount++;
            currentSum = arr[i];  
            if (studentCount > m) {
                return false;
            }
        } else {
            currentSum += arr[i];
        }
    }

    return true;
}

long long findPages(int n, int arr[], int m) {
    if (m > n) {
        return -1; 
    }

    long long low = *max_element(arr, arr + n);
    long long high = accumulate(arr, arr + n, 0LL);
    long long result = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isFeasible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }

    return result;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}
