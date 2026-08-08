#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    map<ll, pair<int, int>> pairs;

    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            ll need = target - arr[j] - arr[k];

            if (pairs.count(need)) {
                auto [i1, i2] = pairs[need];

                cout << i1 + 1 << " " << i2 + 1 << " " << j + 1 << " " << k + 1 << "\n";

                return 0;
            }
        }

        for (int i = 0; i < j; i++)
            pairs[arr[i] + arr[j]] = {i, j};
    }

    cout << "IMPOSSIBLE" << "\n";

    return 0;
}

int main_by_guide() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    set<tuple<int, int, int>> sums;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            sums.emplace(a[i] + a[j], i, j);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            sums.erase({a[i] + a[j], i, j});
        }

        for (int j = i - 1; j >= 1; j--) {
            int diff = x - a[i] - a[j];
            auto it = sums.lower_bound({diff, 0, 0});

            if (it == sums.end()) continue;

            auto [sum, a, b] = *it;

            if (sum != diff) continue;

            cout << i << " " << j << " " << a << " " << b << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
