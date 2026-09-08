#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Bellman Ford Algorithm
// Time Complexity:
// O( V * E ), где:
// V — количество вершин,
// E — количество рёбер.
//
// Space Complexity:
// Memory: O(V)

struct Point {
    int u;
    int v;
    int w;
};

struct Point {
    int u;
    int v;
    long long w;
};

pair<vector<long long>, bool> bellman_ford(
    int n,
    const vector<Point>& edges,
    int start
) {
    const long long INF = 4e18;

    vector<long long> dist(n, INF);

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool updated = false;

        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            long long w = edge.w;

            if (dist[u] == INF) {
                continue;
            }

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }

        if (!updated) {
            break;
        }
    }

    bool has_negative_cycle = false;

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        long long w = edge.w;

        if (dist[u] == INF) {
            continue;
        }

        if (dist[u] + w < dist[v]) {
            has_negative_cycle = true;
            break;
        }
    }

    return {dist, has_negative_cycle};
}

// Bellman–Ford это то же самое что и Dijkstra но чуть медленее и может работать с
// отрицательными рёбрами и может обнаруживать отрицательные циклы

// Bellman–Ford — это "динамическое программирование по количеству рёбер"
// Bellman–Ford не "строит путь", а постепенно улучшает оценки расстояний.
// dp[k][v]
// =
// минимальная стоимость добраться до v
// используя максимум k рёбер

// Where to use:
// Problems like:
// 1. Negative Cycle Detection
// 2. High Score (CSES)
// 3. Currency Arbitrage
// 4. Difference Constraints
