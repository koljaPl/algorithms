#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

struct Edge {
    int u, v;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;

        cin >> u >> v >> w; // From / To / Cost

        u--;
        v--;

        edges.push_back({u, v, w});
    }

    // Bellman-Ford
    vector<ll> dist(n, 0);
    vector<int> parent(n, -1);

    int x = -1;

    for (int i = 0; i < n; i++) {
        x = -1;

        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    // No negative cycle
    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    // Move inside the negative cycle
    for (int i = 0; i < n; i++) {
        x = parent[x];
    }

    // Reconstruct cycle
    vector<int> cycle;

    int cur = x;

    do {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != x);

    cycle.push_back(x);

    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";

    for (int v : cycle) {
        cout << v + 1 << ' ';
    }

    cout << '\n';

    return 0;
}
