#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<pair<ll, int>> arr;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;

        arr.emplace_back(x, i);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            ll s = arr[i].first + arr[l].first + arr[r].first;

            if (s == x) {
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << "\n";
                return 0;
            }

            if (s < x)
                l += 1;
            else
                r -= 1;
        }
    }

    cout << "IMPOSSIBLE" << "\n";

    return 0;
}
