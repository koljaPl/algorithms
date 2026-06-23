#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P {
    ll x;
    ll y;
    int index;
};

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int num) : n(num), bit(num + 1, 0) {}

    void add(int i, int value) {
        while (i <= n) {
            bit[i] += value;
            i += i & -i;
        }
    }

    int prefix_sum(int i) {
        int sum_val = 0;

        while (i > 0) {
            sum_val += bit[i];
            i -= i & -i;
        }

        return sum_val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
        
    vector<P> ranges;
    ranges.reserve(n);

    vector<ll> all_y;
    all_y.reserve(n);

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        ranges.push_back({x, y, i});
        all_y.push_back(y);
    }
        
    sort(ranges.begin(), ranges.end(), [](const P& a, const P& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y > b.y;
    });

    sort(all_y.begin(), all_y.end());
    all_y.erase(unique(all_y.begin(), all_y.end()), all_y.end());
    auto get_comp_y = [&](ll y) {
        return lower_bound(all_y.begin(), all_y.end(), y) - all_y.begin() + 1;
    };

    int max_y_idx = all_y.size();
    vector<int> contains(n, 0);
    vector<int> contained_by(n, 0);

    Fenwick bit1(max_y_idx);
    for (int i = n - 1; i >= 0; i--) {
        int pos = get_comp_y(ranges[i].y);
        contains[ranges[i].index] = bit1.prefix_sum(pos);
        bit1.add(pos, 1);
    }

    Fenwick bit2(max_y_idx);
    int processed = 0;
    for (int i = 0; i < n; i++) {
        int pos = get_comp_y(ranges[i].y);
        contained_by[ranges[i].index] = processed - bit2.prefix_sum(pos - 1);
        bit2.add(pos, 1);
        processed++;
    }

    for (int i = 0; i < n; i++) cout << contains[i] << (i == n - 1 ? "" : " ");
    cout << "\n";

    for (int i = 0; i < n; i++) cout << contained_by[i] << (i == n - 1 ? "" : " ");
    cout << "\n";

    return 0;
}
