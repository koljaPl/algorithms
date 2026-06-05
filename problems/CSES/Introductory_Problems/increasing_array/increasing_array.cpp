#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n = 1;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = 0;

    for (ll i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            res += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }

    cout << res << endl;

    return 0;
}
