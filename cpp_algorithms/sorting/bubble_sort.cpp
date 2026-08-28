#include <iostream>
#include <vector>

using namespace std;

// Bubble Sort V1
//
// Time Complexity:
// O(n^2)
//
// Space Complexity:
// O(1)
void bubble_sort_v1(vector<int>& array) {
    int n = array.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}


// Bubble Sort V2
//
// Time Complexity:
// Worst/Average: O(n^2)
// Best:          O(n)
//
// Space Complexity:
// O(1)
void bubble_sort_v2(vector<int>& array) {
    int n = array.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        // Array is already sorted
        if (!swapped) {
            break;
        }
    }
}


void print_array(const vector<int>& array) {
    for (int x : array) {
        cout << x << ' ';
    }
    cout << '\n';
}


int main() {
    vector<int> not_sorted_array = {2, 8, 5, 3, 9, 4, 1};

    cout << "Before:   ";
    print_array(not_sorted_array);

    vector<int> not_sorted_array_v1 = not_sorted_array;

    bubble_sort_v1(not_sorted_array_v1);

    cout << "After V1: ";
    print_array(not_sorted_array_v1);


    vector<int> not_sorted_array_v2 = not_sorted_array;

    bubble_sort_v2(not_sorted_array_v2);

    cout << "After V2: ";
    print_array(not_sorted_array_v2);

    return 0;
}
