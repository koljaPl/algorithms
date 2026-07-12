#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class FenwickTree {
private:
    int n;
    vector<ll> bit;

public:
    explicit FenwickTree(int size) : n(size), bit(size + 1, 0) {}

    explicit FenwickTree(const vector<int>& values)
        : n(static_cast<int>(values.size())), bit(n + 1, 0) {

        for (int i = 1; i <= n; i++) {
            bit[i] += values[i - 1];

            int parent = i + (i & -i);

            if (parent <= n) {
                bit[parent] += bit[i];
            }
        }
    }

    void add(int i, ll value) {
        while (i <= n) {
            bit[i] += value;
            i += i & -i;
        }
    }

    void subtract(int i, ll value) {
        add(i, -value);
    }

    ll prefix_sum(int i) {
        ll res = 0;

        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }

        return res;
    }

    ll range_sum(int left, int right) {
        return prefix_sum(right) - prefix_sum(left - 1);
    }
};

// Usage example:

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
//
// int main() {
//     FenwickTree fenwick(5);

//     fenwick.add(1, 2);
//     fenwick.add(2, 4);
//     fenwick.add(3, 7);
//     fenwick.add(4, 3);
//     fenwick.add(5, 5);

//     cout << fenwick.prefix_sum(3) << '\n';  // 2 + 4 + 7 = 13
//     cout << fenwick.range_sum(2, 4) << '\n'; // 4 + 7 + 3 = 14

//     fenwick.subtract(3, 2); // the value in position 3 has decreased from 7 to 5

//     cout << fenwick.range_sum(2, 4) << '\n'; // 4 + 5 + 3 = 12
// }
