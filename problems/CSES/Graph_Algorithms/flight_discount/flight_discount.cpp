#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

const ll INF = (ll)4e18;

vector<ll> dijkstra_ioi(
    int n,
    const vector<vector<pair<int, ll>>>& adj,
    int start
) {
    vector<ll> dist(n + 1, INF);
    dist[start] = 0;

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    pq.push({0, start});

    while (!pq.empty()) {
        auto [cur_dist, u] = pq.top();
        pq.pop();

        if (cur_dist != dist[u])
            continue;

        for (auto [v, w] : adj[u]) {
            ll new_dist = cur_dist + w;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    return dist;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> graph(n + 1);
    vector<vector<pair<int, ll>>> reverse_graph(n + 1);

    vector<tuple<int, int, ll>> edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;

        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        reverse_graph[b].push_back({a, c});

        edges.push_back({a, b, c});
    }

    vector<ll> dist1 = dijkstra_ioi(n, graph, 1);

    vector<ll> distN = dijkstra_ioi(n, reverse_graph, n);

    ll res = INF;

    for (auto [a, b, c] : edges) {
        ll cost = dist1[a] + c / 2 + distN[b];
        res = min(res, cost);
    }

    cout << res << '\n';

    return 0;
}
