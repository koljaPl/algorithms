#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 1000000007;
    int n;
    cin >> n;

    ll total_sum = (ll)n * (n + 1) / 2;

    if (total_sum % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    ll target = total_sum / 2;

    vector<ll> dp(target + 1, 0);
    dp[0] = 1;

    for (int x = 1; x <= n; x++) {
        for (ll curr_sum = target; curr_sum >= x; curr_sum--) {
            dp[curr_sum] += dp[curr_sum - x];

            if (dp[curr_sum] >= MOD) {
                dp[curr_sum] -= MOD;
            }
        }
    }

    cout << dp[target] * 500000004 % MOD << "\n";

    return 0;
}
