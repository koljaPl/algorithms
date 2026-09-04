#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Selection Sort

// Time Complexity:      θ(n ** 2), Ω(n ** 2)

// Space Complexity :    O(1)

vector<int> selection_sort(vector<int> array) {
    int n = array.size();

    for (int i = 0; i < n; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(array[i], array[min_index]);
        }
    }

    return array;
}

int main() {
    vector<int> not_sorted_array = {2, 8, 5, 3, 9, 4, 1};

    cout << "Before: ";

    for (int x : not_sorted_array) {
        cout << x << ' ';
    }

    cout << '\n';

    vector<int> sorted_array = selection_sort(not_sorted_array);

    cout << "After:  ";

    for (int x : sorted_array) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
