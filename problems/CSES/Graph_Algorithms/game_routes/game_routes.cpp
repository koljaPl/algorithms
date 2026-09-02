#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 1e9 + 7;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    vector<int> indegree(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a - 1].pb(b - 1);

        indegree[b - 1]++;
    }

    queue<int> q;

    for (int v = 0; v < n; v++) {
        if (indegree[v] == 0) {
            q.push(v);
        }
    }

    vector<int> dp(n, 0);

    dp[0] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : graph[v]) {
            dp[u] = (dp[u] + dp[v]) % MOD;

            indegree[u]--;

            if (indegree[u] == 0) {
                q.push(u);
            }
        }
    }

    cout << dp[n - 1] << '\n';

    return 0;
}
