#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> cnt(n, 0);
    cnt[0] = 1;

    ll pref = 0;
    ll res = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        
        pref = ((pref + x) % n + n) % n;

        res += cnt[pref];
        cnt[pref] += 1;
    }

    cout << res;

    return 0;
}
