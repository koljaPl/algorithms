#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> cnt(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        cnt[a][b]++;
    }

    if (n == 2) {
        cout << cnt[0][1] % MOD << '\n';
        return 0;
    }

    int k = n - 2;
    int size = 1 << k;

    vector<int> incoming(k, 0);
    for (int j = 0; j < k; j++) {
        int city_j = j + 1;

        for (int u = 0; u < k; u++) {
            int city_u = u + 1;

            if (cnt[city_u][city_j])
                incoming[j] |= (1 << u);
        }
    }

    vector<int> dp((ll)size * k, 0);
    for (int j = 0; j < k; j++) {
        dp[(1 << j) * k + j] = cnt[0][j + 1] % MOD;
    }

    for (int mask = 1; mask < size; mask++) {
        int bits = mask;

        while (bits) {
            int bit = bits & -bits;
            int j = __builtin_ctz(bit);

            int prev_mask = mask ^ bit;

            if (prev_mask != 0) {
                ll total = 0;

                int prev_bits = prev_mask & incoming[j];

                while (prev_bits) {
                    int prev_bit = prev_bits & -prev_bits;
                    int u = __builtin_ctz(prev_bit);

                    total += 1LL * dp[prev_mask * k + u] * cnt[u + 1][j + 1];

                    if (total >= (1LL << 62)) total %= MOD;

                    prev_bits -= prev_bit;
                }

                dp[mask * k + j] = total % MOD;
            }

            bits -= bit;
        }
    }

    int full_mask = size - 1;

    ll res = 0;

    for (int j = 0; j < k; j++) {
        res += 1LL * dp[full_mask * k + j] * cnt[j + 1][n - 1];

        res %= MOD;
    }

    cout << res % MOD << '\n';

    return 0;
}
