#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<ll>> projects(n, vector<ll>(3));
    for (int i = 0; i < n; i++) {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }

    sort(projects.begin(), projects.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[1] < b[1];
    });

    vector<ll> ends(n);
    for (int i = 0; i < n; i++) {
        ends[i] = projects[i][1];
    }

    vector<ll> dp(n + 1, 0);

    for (int i = 1; i < n + 1; i++) {
        ll start = projects[i - 1][0];
        ll end = projects[i - 1][1];
        ll reward = projects[i - 1][2];

        int compatible_count = lower_bound(ends.begin(), ends.end(), start) - ends.begin();

        ll skip_current = dp[i - 1];
        ll take_current = reward + dp[compatible_count];

        dp[i] = max(skip_current, take_current);

    }

    cout << dp[n] << "\n";

    return 0;
}
