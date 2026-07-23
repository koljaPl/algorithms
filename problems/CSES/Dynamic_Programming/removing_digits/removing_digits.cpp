#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int INF = 1e9;

    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int number = 1; number <= n + 1; number++) {
        int value = number;

        while (value > 0) {
            int digit = value % 10;
            value /= 10;

            if (digit != 0) {
                dp[number] = min(dp[number], dp[number - digit] + 1);
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}
