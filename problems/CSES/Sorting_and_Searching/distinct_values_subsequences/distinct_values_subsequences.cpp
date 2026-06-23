#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<ll, int> counts;
    counts.reserve(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        counts[x]++;
    }

    ll res = 1;
    for (const auto& [key, value] : counts) res = (res * (value + 1)) % MOD;

    cout << (res - 1 + MOD) % MOD << "\n";

    return 0;
}
