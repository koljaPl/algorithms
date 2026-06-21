#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> ks(n);
    for (int i = 0; i < n; i++) cin >> ks[i];

    set<ll> seen;
    ll left = 0;
    ll res = 0;

    for (ll right = 0; right < n; right++) {
        while (seen.contains(ks[right])) {
            seen.erase(ks[left]);
            left++;
        }

        seen.insert(ks[right]);
        res = max(res, right - left + 1);
    }

    cout << res << "\n";

    return 0;
}
