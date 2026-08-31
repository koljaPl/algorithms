#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Kruskal's Algorithm:
//
// Time Complexity:
//
// Sorting Part: O(E log E) ≈ O(E log V)
//
// DSU operations:
// почти O(1)
// точнее O(alpha(V)) амортизированно
//
// Total:
// O(E log E)
//
// Space Complexity:
// O(V + E)

class DSU {
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if (parent[v] != v) {
            parent[v] = find(parent[v]); // path compression
        }

        return parent[v];
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return false;
        }

        // union by size
        if (sz[u] < sz[v]) {
            swap(u, v);
        }

        parent[v] = u;
        sz[u] += sz[v];

        return true;
    }
};


pair<ll, vector<tuple<int, int, ll>>> kruskal_algorithm(
    int n,
    vector<tuple<ll, int, int>> edges
) {
    /*
        n: number of vertices (0...n-1)

        edges:
        (weight, u, v)

        return:
        (mst_weight, mst_edges)
    */

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    ll mst_weight = 0;
    vector<tuple<int, int, ll>> mst_edges;

    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            mst_weight += w;
            mst_edges.push_back({u, v, w});
        }

        if ((int)mst_edges.size() == n - 1) {
            break;
        }
    }

    return {mst_weight, mst_edges};
}
