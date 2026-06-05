#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b;
    cin >> a >> b;

    if ((a + b) % 3 != 0) {
        cout << "NO" << endl;
    } else {
        if (min(a, b) * 2 >= max(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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
