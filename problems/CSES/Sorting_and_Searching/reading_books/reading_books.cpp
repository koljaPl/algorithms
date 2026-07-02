#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr;
    ll max_value = -INF;
    ll total_sum = 0;
    
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        arr.push_back(x);

        max_value = max(max_value, x);
        total_sum += x;
    }

    cout << max(total_sum, max_value * 2) << "\n";

    return 0;
}
