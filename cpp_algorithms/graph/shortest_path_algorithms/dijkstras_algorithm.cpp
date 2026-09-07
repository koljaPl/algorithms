#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Dijkstra's Algorithm
// Time Complexity:
// O( ( V + E ) log V ), где:
// V — количество вершин,
// E — количество рёбер.
//
// Space Complexity:
// Memory: O( V + E )


// Standard Dijkstra
vector<long long> dijkstra(
    int n,
    const vector<vector<pair<int, int>>>& adj,
    int start
) {
    const long long INF = LLONG_MAX;

    vector<long long> dist(n, INF);
    dist[start] = 0;

    // Min-Heap / Priority Queue
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > priority_queue;

    // (distance, node)
    priority_queue.push({0, start});

    while (!priority_queue.empty()) {
        auto [cur_dist, u] = priority_queue.top();
        priority_queue.pop();

        // outdated entry
        if (cur_dist > dist[u]) {
            continue;
        }

        for (auto [v, w] : adj[u]) {
            long long new_dist = cur_dist + w;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                priority_queue.push({new_dist, v});
            }
        }
    }

    return dist;
}


// Dijkstra with path reconstruction
pair<vector<long long>, vector<int>> dijkstra_with_path(
    int n,
    const vector<vector<pair<int, int>>>& adj,
    int start
) {
    const long long INF = LLONG_MAX;

    vector<long long> dist(n, INF);
    vector<int> parent(n, -1);

    dist[start] = 0;

    // Min-Heap / Priority Queue
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > priority_queue;

    priority_queue.push({0, start});

    while (!priority_queue.empty()) {
        auto [cur_dist, u] = priority_queue.top();
        priority_queue.pop();

        if (cur_dist > dist[u]) {
            continue;
        }

        for (auto [v, w] : adj[u]) {
            long long new_dist = cur_dist + w;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                parent[v] = u;

                priority_queue.push({new_dist, v});
            }
        }
    }

    return {dist, parent};
}


// Or more IOI version of Dijkstra:
vector<long long> dijkstra_ioi(
    int n,
    const vector<vector<pair<int, int>>>& adj,
    int start
) {
    const long long INF = (long long)1e18 + 1;

    vector<long long> dist(n, INF);
    dist[start] = 0;

    // Min-Heap / Priority Queue
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > priority_queue;

    priority_queue.push({0, start});

    while (!priority_queue.empty()) {
        auto [cur_dist, u] = priority_queue.top();
        priority_queue.pop();

        // Это то же самое что и > потому что мы используем Heap,
        // а у Heap есть особенность делать только меньшее число наверх
        // тоесть: разрешаем только единственную актуальную версию
        // что значит что мы утверждаем что точно есть 1 правильный путь
        if (cur_dist != dist[u]) {
            continue;
        }

        for (auto [v, w] : adj[u]) {
            long long new_dist = cur_dist + w;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;

                priority_queue.push({new_dist, v});
            }
        }
    }

    return dist;
}
