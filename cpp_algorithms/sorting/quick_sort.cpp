#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Quick Sort (Divide and Conquer)
//
// Time Complexity:
// Worst: O(n**2)
// Average: O(n log n)
// Best: O(n log n)
//
// Space Complexity:
// Worst: O(n)
// Average/Best: O(log n)

int partition(vector<int>& array, int low, int high) {
    int pivot = array[low];
    int leftwall = low + 1;

    for (int i = low + 1; i <= high; ++i) {
        if (array[i] < pivot) {
            swap(array[i], array[leftwall]);
            leftwall++;
        }
    }

    swap(array[low], array[leftwall - 1]);

    return leftwall - 1;
}

void quick_sort(vector<int>& array, int low, int high) {
    if (low < high) {
        int pivot_location = partition(array, low, high);

        quick_sort(array, low, pivot_location - 1);
        quick_sort(array, pivot_location + 1, high);
    }
}

int main() {
    vector<int> array = {2, 8, 5, 3, 9, 4, 1};

    cout << "Before: ";
    for (int x : array) {
        cout << x << ' ';
    }
    cout << '\n';

    quick_sort(array, 0, array.size() - 1);

    cout << "After:  ";
    for (int x : array) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
