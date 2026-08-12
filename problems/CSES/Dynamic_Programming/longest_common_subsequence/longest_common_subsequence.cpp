#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int& x : a) {
        cin >> x;
    }

    for (int& x : b) {
        cin >> x;
    }

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0)
    );

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    vector<int> sequence;

    int i = n;
    int j = m;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            sequence.push_back(a[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(sequence.begin(), sequence.end());

    cout << sequence.size() << '\n';

    for (int x : sequence) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
