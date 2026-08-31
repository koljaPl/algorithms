#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a - 1].push_back({b - 1, c});
    }

    const ll INF = 4e18;

    vector<ll> dist(n, INF);
    vector<int> parent(n, -1);

    dist[0] = 0;

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    pq.push({0, 0});

    while (!pq.empty()) {
        auto [cur_dist, u] = pq.top();
        pq.pop();

        if (cur_dist > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            ll new_dist = cur_dist + w;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                parent[v] = u;

                pq.push({new_dist, v});
            }
        }
    }

    for (ll d : dist) cout << d << ' ';

    cout << '\n';

    return 0;
}
