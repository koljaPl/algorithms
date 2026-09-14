#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

class DSU {
private:
    vector<int> parents;
    vector<int> sz;

public:
    DSU(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);

        sz.assign(n, 1);
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]); // Path Compression
        }

        return parents[x];
    }

    int unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return 0;
        }

        if (sz[u] < sz[v]) {
            swap(u, v);
        }

        parents[v] = u;
        sz[u] += sz[v];

        return sz[u];
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    int get_size(int x) {
        return sz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    int components = n;
    int largest = 1;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        int new_sz = dsu.unite(a, b);
        if (new_sz > 0) {
            components--;
            largest = max(largest, new_sz);
        }

        cout << components << ' ' << largest << '\n';
    }

    return 0;
}
