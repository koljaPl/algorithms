#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Prim's algorithm:
// Time Complexity:
// O((V + E) log V)
//
// Space Complexity:
// O(V + E)

ll prims_algorithm(int n, const vector<vector<pair<int, ll>>>& graph) {
    vector<bool> visited(n, false);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> min_heap;

    ll mst_weight = 0;

    visited[0] = true;

    for (auto [to, w] : graph[0]) {
        min_heap.push({w, to});
    }

    int edges_used = 0;

    while (!min_heap.empty() && edges_used < n - 1) {
        auto [w, v] = min_heap.top();
        min_heap.pop();

        if (visited[v]) {
            continue;
        }

        visited[v] = true;

        mst_weight += w;
        edges_used++;

        for (auto [to, cost] : graph[v]) {
            if (!visited[to]) {
                min_heap.push({cost, to});
            }
        }
    }

    if (edges_used != n - 1) {
        return -1;
    }

    return mst_weight;
}
