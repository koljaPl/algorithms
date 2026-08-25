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
    vector<vector<int>> reverse_graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;

        cin >> a >> b >> x;

        a--;
        b--;

        edges.push_back({a, b, x});
        reverse_graph[b].push_back(a);
    }

    vector<bool> can_reach_n(n, false);

    queue<int> q;
    q.push(n - 1);
    can_reach_n[n - 1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : reverse_graph[u]) {
            if (!can_reach_n[v]) {
                can_reach_n[v] = true;
                q.push(v);
            }
        }
    }

    const ll NEG_INF = -(1LL << 60);

    vector<ll> dist(n, NEG_INF);
    dist[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool changed = false;

        for (auto [u, v, w] : edges) {
            if (dist[u] == NEG_INF)
                continue;

            if (dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }

        if (!changed)
            break;
    }

    for (auto [u, v, w] : edges) {
        if (dist[u] == NEG_INF)
            continue;

        if (dist[u] + w > dist[v]) {
            if (can_reach_n[v]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << dist[n - 1] << '\n';

    return 0;
}
