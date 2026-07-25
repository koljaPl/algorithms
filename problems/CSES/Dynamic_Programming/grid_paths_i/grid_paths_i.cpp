#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 1'000'000'007;

    int n;
    cin >> n;

    vector<string> grid(n);

    for (string& row : grid) {
        cin >> row;
    }

    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') {
                dp[j] = 0;
            } else if (j > 0) {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1] << '\n';

    return 0;
}
