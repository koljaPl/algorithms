#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    ll sum = n + m;
    ll diff = abs(n - m);
    ll mult = n * m;
    ll div = n / m;
    ll mod = n % m;

    n++;
    m--;

    vector<ll> arr = {sum, diff, mult, div, mod, n, m};

    for (auto value : arr) {
        cout << value << " ";
    }
    cout << "\n";
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
