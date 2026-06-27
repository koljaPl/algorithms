#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    
    vector<ll> coins(n);
    
    for (int i = 0; i < n; ++i) 
        cin >> coins[i];

    sort(coins.begin(), coins.end());

    ll res = 1;
    for (ll coin : coins) {
        if (coin > res) break;

        res += coin;
    }

    cout << res << '\n';

    return 0;
}
