#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main_v1() {
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

                if (dp[curr_sum] >= MOD) {
                    dp[curr_sum] -= MOD;
                }
            }
        }
    }

    cout << dp[target] << "\n";

    return 0;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int j = 0; j < n; ++j) {
        cin >> c[j];
    }

    vector<int> ways(x + 1);
    ways[0] = 1;
    for (int i = 1; i <= x; ++i) {
        ways[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (i - c[j] >= 0) {
                ways[i] = (ways[i] + ways[i - c[j]]) % MOD;
            }
        }
    }

    cout << ways[x] << "\n";
}
