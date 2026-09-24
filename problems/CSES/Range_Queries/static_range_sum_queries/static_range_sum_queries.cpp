#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    FenwickTree tree(n);
    for (int i = 0; i < n; i++) tree.add(i + 1, arr[i]);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cout << tree.range_sum(a, b) << "\n";
    }

    return 0;
}
