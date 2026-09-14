#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Binary Search

// Time Complexity:      O(log n)
// Space Complexity :    O(1)
// Number of Steps:      O(log n)
int binary_search(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        // or mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}
