#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Range {
    ll a;
    ll b;
    int i;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Range> ranges;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        ranges.push_back({x, y, i});
    }

    sort(ranges.begin(), ranges.end(), [](auto& a, auto& b) {
        if (a.a != b.a)
            return a.a < b.a;

        return a.b > b.b;
    });

    vector<int> contains(n, 0);
    vector<int> contained_by(n, 0);

    ll min_y = LLONG_MAX;
    for (int i = n - 1; 0 <= i; i--) {
        ll y;
        int original_index;
        y = ranges[i].b;
        original_index = ranges[i].i;

        if (y >= min_y) {
            contains[original_index] = 1;
        } else {
            min_y = y;
        }
    }

    ll max_y = 0;
    for (int i = 0; i < n; i++) {
        ll y;
        int original_index;
        y = ranges[i].b;
        original_index = ranges[i].i;

        if (y <= max_y) {
            contained_by[original_index] = 1;
        } else {
            max_y = y;
        }
    }

    for (int contain : contains) cout << contain << " ";
    cout << "\n";

    for (int contained : contained_by) cout << contained << " ";
    cout << "\n";

    return 0;
}
