#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

class DSU {
private:
    vector<int> parents;
    vector<int> size;

public:
    DSU(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);

        size.assign(n, 1);
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]); // Path Compression
        }

        return parents[x];
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return false;
        }

        if (size[u] < size[v]) {
            swap(u, v);
        }

        parents[v] = u;
        size[u] += size[v];

        return true;
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<long long, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;

        cin >> a >> b >> c;

        edges.push_back({c, a - 1, b - 1});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    ll res = 0;
    int used_edges = 0;

    for (auto [cost, a, b] : edges) {
        if (dsu.unite(a, b)) {
            res += cost;
            used_edges++;

            if (used_edges == n - 1) {
                break;
            }
        }
    }

    if (used_edges != n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << res << '\n';
    }

    return 0;
}
