#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    const int INF = 1e9;

    vector<int> dist(n + 1, -INF);
    vector<int> parent(n + 1, 0);

    dist[1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[u] != -INF && dist[u] + 1 > dist[v]) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }

            in_degree[v]--;

            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (dist[n] < 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n] << '\n';

        vector<int> path;

        int curr = n;

        while (curr != 0) {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());

        for (int v : path) {
            cout << v << ' ';
        }

        cout << '\n';
    }

    return 0;
}
