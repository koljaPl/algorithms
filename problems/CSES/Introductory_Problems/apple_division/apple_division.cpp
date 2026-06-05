#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;

    vector<ll> list_a(n);
    for (int i = 0; i < n; i++) {
        cin >> list_a[i];
    }

    ll total = accumulate(list_a.begin(), list_a.end(), 0LL);
    ll res = numeric_limits<ll>::max(); 
    
    auto dfs = [&](auto& self, int i, ll curr_sum) -> void {
        if (i == n) {
            res = min(res, abs(total - 2 * curr_sum));
            return;
        }
        self(self, i + 1, curr_sum + list_a[i]);
        self(self, i + 1, curr_sum);
    };

    dfs(dfs, 0, 0);

    cout << res << '\n';

    return 0;
}
