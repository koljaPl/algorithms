#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Merge Sort (my favorite method - divide and conquer)

vector<int> not_sorted_array = {2, 8, 5, 3, 9, 4, 1};

// Time Complexity:
// θ(n log n)
//
// Space Complexity:
// O(n)

vector<int> merge_v1(vector<int> left, vector<int> right) {
    vector<int> array;

    while (!left.empty() && !right.empty()) {
        if (left[0] < right[0]) {
            array.push_back(left[0]);
            left.erase(left.begin());
        } else {
            array.push_back(right[0]);
            right.erase(right.begin());
        }
    }

    while (!left.empty()) {
        array.push_back(left[0]);
        left.erase(left.begin());
    }

    while (!right.empty()) {
        array.push_back(right[0]);
        right.erase(right.begin());
    }

    return array;
}


vector<int> merge_sort_v1(vector<int> array) {
    int n = array.size();

    if (n <= 1) {
        return array;
    }

    vector<int> left_array(
        array.begin(),
        array.begin() + n / 2
    );

    vector<int> right_array(
        array.begin() + n / 2,
        array.end()
    );

    vector<int> left = merge_sort_v1(left_array);
    vector<int> right = merge_sort_v1(right_array);

    return merge_v1(left, right);
}


deque<int> merge_v2(deque<int> left, deque<int> right) {
    deque<int> array;

    while (!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            array.push_back(left.front());
            left.pop_front();
        } else {
            array.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty()) {
        array.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty()) {
        array.push_back(right.front());
        right.pop_front();
    }

    return array;
}


deque<int> merge_sort_v2(vector<int> array) {
    int n = array.size();

    if (n <= 1) {
        return deque<int>(array.begin(), array.end());
    }

    vector<int> left_array(
        array.begin(),
        array.begin() + n / 2
    );

    vector<int> right_array(
        array.begin() + n / 2,
        array.end()
    );

    deque<int> left = merge_sort_v2(left_array);
    deque<int> right = merge_sort_v2(right_array);

    return merge_v2(left, right);
}


int main() {
    cout << "Before:    ";

    for (int x : not_sorted_array) {
        cout << x << ' ';
    }

    cout << '\n';


    vector<int> sorted_v1 = merge_sort_v1(not_sorted_array);

    cout << "After V1:  ";

    for (int x : sorted_v1) {
        cout << x << ' ';
    }

    cout << '\n';


    deque<int> sorted_v2 = merge_sort_v2(not_sorted_array);

    cout << "After V2:  ";

    for (int x : sorted_v2) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
