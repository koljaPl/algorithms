#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n = 1;
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        ll x = i * i;
        ll total_squares = x * (x - 1) / 2;
        ll attacking_squares = 4 * (i - 1) * (i - 2);

        cout << total_squares - attacking_squares << "\n";
    }

    return 0;
}
