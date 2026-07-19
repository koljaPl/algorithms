#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<ll> count(n, 0);
    count[0] = 1;

    ll pref = 0;
    ll res = 0;

    for (ll x : arr) {
        pref = (pref + x) % n;

        if (pref < 0) pref += n;

        res += count[pref];
        count[pref]++;
    }

    cout << res << "\n";

    return 0;
}