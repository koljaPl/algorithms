#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

const ll INF = 4e18;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;

        cin >> a >> b >> c;

        a--;
        b--;

        graph[a].push_back({b, c});
    }


    vector<ll> dist(n, INF);
    vector<ll> ways(n);

    vector<int> min_flights(n, 1e9);
    vector<int> max_flights(n);


    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;


    dist[0] = 0;
    ways[0] = 1;
    min_flights[0] = 0;

    pq.push({0, 0});


    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d != dist[v]) {
            continue;
        }

        for (auto [u, w] : graph[v]) {
            ll new_dist = d + w;

            if (new_dist < dist[u]) {
                dist[u] = new_dist;

                ways[u] = ways[v];

                min_flights[u] = min_flights[v] + 1;
                max_flights[u] = max_flights[v] + 1;

                pq.push({new_dist, u});
            }

            else if (new_dist == dist[u]) {
                ways[u] = (ways[u] + ways[v]) % MOD;

                min_flights[u] = min(
                    min_flights[u],
                    min_flights[v] + 1
                );

                max_flights[u] = max(
                    max_flights[u],
                    max_flights[v] + 1
                );
            }
        }
    }


    cout << dist[n - 1] << ' '
         << ways[n - 1] << ' '
         << min_flights[n - 1] << ' '
         << max_flights[n - 1] << '\n';

    return 0;
}
