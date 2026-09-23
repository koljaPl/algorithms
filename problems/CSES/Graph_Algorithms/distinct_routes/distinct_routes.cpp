#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

struct Edge {
    int to;
    int rev;
    int cap;
    bool original;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    auto add_edge = [&](int u, int v) {
        Edge forward{v, (int)graph[v].size(), 1, true};
        Edge backward{u, (int)graph[u].size(), 0, false};

        graph[u].pb(forward);
        graph[v].pb(backward);
    };

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        add_edge(a, b);
    }

    int source = 0;
    int sink = n - 1;

    vector<int> level(n);
    vector<int> ptr(n);

    auto bfs = [&]() -> bool {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;

        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const Edge &e : graph[u]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }

        return level[sink] != -1;
    };

    function<int(int, int)> dfs = [&](int u, int pushed) -> int {
        if (u == sink) return pushed;

        while (ptr[u] < (int)graph[u].size()) {
            Edge &e = graph[u][ptr[u]];

            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                int flow = dfs(e.to, min(pushed, e.cap));

                if (flow) {
                    e.cap -= flow;
                    graph[e.to][e.rev].cap += flow;
                    return flow;
                }
            }

            ptr[u]++;
        }

        return 0;
    };

    int res = 0;
    while (bfs()) {
        fill(ptr.begin(), ptr.end(), 0);

        while (true) {
            int pushed = dfs(source, 1e9);

            if (!pushed) break;

            res += pushed;
        }
    }

    auto find_path = [&]() -> vector<int> {
        vector<pair<int, int>> parent(n, {-1, -1});
        vector<bool> visited(n, false);

        visited[source] = true;

        queue<int> q;
        q.push(source);

        while (!q.empty() && !visited[sink]) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < (int)graph[u].size(); ++i) {
                Edge &e = graph[u][i];

                if (e.original && e.cap == 0 && !visited[e.to]) {
                    visited[e.to] = true;
                    parent[e.to] = {u, i};
                    q.push(e.to);
                }
            }
        }

        vector<int> path;

        int v = sink;
        while (v != source) {
            auto [u, edge_index] = parent[v];

            path.pb(v);

            Edge &e = graph[u][edge_index];
            e.cap = 1;

            v = u;
        }

        path.pb(source);
        reverse(path.begin(), path.end());

        return path;
    };

    cout << res << '\n';
    for (int i = 0; i < res; ++i) {
        vector<int> path = find_path();

        cout << path.size() << '\n';

        for (int v : path)
            cout << v + 1 << ' ';
        cout << '\n';
    }

    return 0;
}
