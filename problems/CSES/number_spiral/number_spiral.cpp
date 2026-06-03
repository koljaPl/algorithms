#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll y, x;
    cin >> y >> x;

    if (y > x) {
        if (y % 2 == 0) {
            cout << (y * y - x + 1) << "\n";
        } else {
            cout << ((y - 1) * (y - 1) + x) << "\n";
        }
    } else {
        if (x % 2 == 0) {
            cout << ((x - 1) * (x - 1) + y) << "\n";
        } else {
            cout << (x * x - y + 1) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
