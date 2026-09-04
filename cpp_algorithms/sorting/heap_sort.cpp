#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Heap Sort

vector<int> not_sorted_array = {2, 8, 5, 3, 9, 4, 1};

// Time Complexity:     θ(n log n), Ω(n log n)
// Space Complexity :   O(log n)

// Time: O(log n), called n - 1 times
void heapify(vector<int>& array, int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && array[left] > array[largest]) {
        largest = left;
    }
    else {
        largest = i;
    }

    if (right < n && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, largest, n);
    }
}

// Time: O(n)
void build_max_heap(vector<int>& array) {
    int n = array.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, i, n);
    }
}

vector<int> heap_sort(vector<int> array) {
    int n = array.size();

    build_max_heap(array);

    for (int i = array.size() - 1; i > 0; i--) {
        swap(array[0], array[i]);

        n = n - 1;

        heapify(array, 0, n);
    }

    return array;
}

int main() {
    cout << "Before: ";

    for (int x : not_sorted_array) {
        cout << x << " ";
    }

    cout << "\n";

    vector<int> sorted_array = heap_sort(not_sorted_array);

    cout << "After:  ";

    for (int x : sorted_array) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}
