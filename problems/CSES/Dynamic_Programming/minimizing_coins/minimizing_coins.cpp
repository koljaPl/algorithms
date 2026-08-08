#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    const int INF = 1e9;

    vector<int> dp(target + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        int coin;
        cin >> coin;

        for (int j = coin; j <= target; ++j) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    if (dp[target] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[target] << "\n";
    }

    return 0;
}
