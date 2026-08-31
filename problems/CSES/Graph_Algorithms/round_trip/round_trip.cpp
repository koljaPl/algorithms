#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;

int cycle_start = -1;
int cycle_end = -1;

bool dfs(int u, int p) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (v == p)
            continue;

        if (visited[v]) {
            cycle_start = v;
            cycle_end = u;
            return true;
        }

        parent[v] = u;

        if (dfs(v, u))
            return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    graph.resize(n + 1);
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;

    cycle.push_back(cycle_start);

    int cur = cycle_end;

    while (cur != cycle_start) {
        cycle.push_back(cur);
        cur = parent[cur];
    }

    cycle.push_back(cycle_start);

    cout << cycle.size() << '\n';

    for (int node : cycle) {
        cout << node << ' ';
    }

    cout << '\n';

    return 0;
}
