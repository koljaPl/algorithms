#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    int n = max(h, w);

    vector<vector<int>> dp(
        n + 1,
        vector<int>(n + 1, 0)
    );

    for (int b = 1; b <= n; ++b) {
        for (int a = 1; a <= b; ++a) {
            if (a == b) {
                continue;
            }

            int best = a * b - 1;

            for (int cut = 1; cut <= a / 2; ++cut) {
                int candidate =
                    1 +
                    dp[cut][b] +
                    dp[a - cut][b];

                best = min(best, candidate);
            }

            for (int cut = 1; cut <= b / 2; ++cut) {
                int firstA = min(a, cut);
                int firstB = max(a, cut);

                int second = b - cut;
                int secondA = min(a, second);
                int secondB = max(a, second);

                int candidate =
                    1 +
                    dp[firstA][firstB] +
                    dp[secondA][secondB];

                best = min(best, candidate);
            }

            dp[a][b] = best;
            dp[b][a] = best;
        }
    }

    cout << dp[h][w] << '\n';

    return 0;
}
