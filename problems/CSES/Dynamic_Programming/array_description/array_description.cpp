#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int& value : arr) {
        cin >> value;
    }

    vector<int> prev(m + 2, 0);

    if (arr[0] == 0) {
        for (int value = 1; value <= m; ++value) {
            prev[value] = 1;
        }
    } else {
        prev[arr[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        vector<int> curr(m + 2, 0);

        if (arr[i] == 0) {
            for (int value = 1; value <= m; ++value) {
                curr[value] = (
                    1LL * prev[value - 1] +
                    prev[value] +
                    prev[value + 1]
                ) % MOD;
            }
        } else {
            int value = arr[i];

            curr[value] = (
                1LL * prev[value - 1] +
                prev[value] +
                prev[value + 1]
            ) % MOD;
        }

        prev = move(curr);
    }

    int sum = 0;

    for (int value = 1; value <= m; ++value) {
        sum += prev[value];

        if (sum >= MOD) {
            sum -= MOD;
        }
    }

    cout << sum << '\n';

    return 0;
}
