#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n = 1;
    cin >> n;

    vector<ll> a(n);
    for (auto i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << abs(accumulate(a.begin(), a.end(), 0LL) - n * (n + 1) / 2) << "\n";

    return 0;
}
