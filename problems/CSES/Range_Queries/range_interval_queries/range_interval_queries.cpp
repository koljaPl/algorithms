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

    vector<int> x(n);
    for (int &v : x) cin >> v;

    vector<pair<int, int>> elements;
    for (int i = 0; i < n; ++i) elements.pb({x[i], i + 1});

    sort(elements.begin(), elements.end());

    vector<tuple<int, int, int, int, int>> events;
    for (int qi = 0; qi < q; ++qi) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        events.pb({d, qi, 1, a, b});
        events.pb({c - 1, qi, -1, a, b});
    }

    sort(events.begin(), events.end());

    FenwickTree fw(n);

    vector<int> res(q, 0);

    int j = 0;
    for (auto [threshold, qi, sign, a, b] : events) {
        while (j < n && elements[j].first <= threshold) {
            int pos = elements[j].second;

            fw.add(pos, 1);

            j++;
        }

        res[qi] += sign * fw.range_sum(a, b);
    }

    for (int num : res) cout << num << '\n';

    return 0;
}
