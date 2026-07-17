#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int curr_sum = 1; curr_sum < target + 1; curr_sum++) {
        for (int coin : coins) {
            if (curr_sum >= coin) {
                dp[curr_sum] += dp[curr_sum - coin];

                if (dp[curr_sum] >= 1e9 + 7) {
                    dp[curr_sum] -= 1e9 + 7;
                }
            }
        }
    }

    cout << dp[target] << "\n";

    return 0;
}
