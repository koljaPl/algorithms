#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> transitions;

void generate(int row, int mask, int next_mask) {
    if (row == n) {
        transitions[mask].push_back(next_mask);
        return;
    }

    if (mask & (1 << row)) {
        generate(row + 1, mask, next_mask);
        return;
    }

    generate(
        row + 1,
        mask,
        next_mask | (1 << row)
    );

    if (
        row + 1 < n &&
        !(mask & (1 << (row + 1)))
    ) {
        generate(
            row + 2,
            mask,
            next_mask
        );
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int mask_count = 1 << n;

    transitions.resize(mask_count);

    for (int mask = 0; mask < mask_count; mask++) {
        generate(0, mask, 0);
    }

    vector<ll> dp(mask_count, 0);
    dp[0] = 1;

    for (int col = 0; col < m; col++) {
        vector<ll> next_dp(mask_count, 0);

        for (int mask = 0; mask < mask_count; mask++) {
            ll ways = dp[mask];

            if (ways == 0) {
                continue;
            }

            for (int next_mask : transitions[mask]) {
                next_dp[next_mask] += ways;

                if (next_dp[next_mask] >= MOD) {
                    next_dp[next_mask] -= MOD;
                }
            }
        }

        dp = move(next_dp);
    }

    cout << dp[0] << '\n';

    return 0;
}
