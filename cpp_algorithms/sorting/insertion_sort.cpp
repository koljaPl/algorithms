#include <iostream>
#include <vector>

using namespace std;

// Insertion Sort
vector<int> not_sorted_array = {2, 8, 5, 3, 9, 4, 1};

// Time Complexity:      θ(n²), Ω(n)
// Space Complexity :    O(1)
vector<int> insertion_sort_v1(vector<int> array) {
    int n = array.size();

    for (int i = 1; i < n; i++) {

        int j = i;

        while (j > 0 && array[j - 1] > array[j]) {

            swap(array[j], array[j - 1]);

            j -= 1;
        }
    }

    return array;
}

// Time Complexity:      θ(n²), Ω(n)
// Space Complexity :    O(1)
vector<int> insertion_sort_v2(vector<int> array) {
    int n = array.size();

    for (int i = 1; i < n; i++) {

        int key = array[i];

        int j = i - 1;

        while (j >= 0 && array[j] > key) {

            array[j + 1] = array[j];

            j -= 1;
        }

        array[j + 1] = key;
    }

    return array;
}

void print_array(const vector<int>& array) {
    for (int x : array) {
        cout << x << " ";
    }

    cout << "\n";
}

int main() {

    cout << "Before:   ";
    print_array(not_sorted_array);

    cout << "After V1: ";
    print_array(insertion_sort_v1(not_sorted_array));


    cout << "After V2: ";
    print_array(insertion_sort_v2(not_sorted_array));

    return 0;
}
