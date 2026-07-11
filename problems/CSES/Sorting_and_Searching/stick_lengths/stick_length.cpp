#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> lengths(n);

    for (int i = 0; i < n; i++) cin >> lengths[i];
    sort(lengths.begin(), lengths.end());

    ll res = 0;
    ll needed = lengths[n / 2];

    for (int i = 0; i < n; i++) {
        res += abs(lengths[i] - needed);
    }

    cout << res << "\n";

    return 0;
}
