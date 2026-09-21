#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

struct Edge {
    int to;
    int rev;
    ll cap;
};

void add_edge(vector<vector<Edge>>& graph, int u, int v, ll cap) {
    graph[u].pb({v, (int)graph[v].size(), cap});
    graph[v].pb({u, (int)graph[u].size() - 1, 0});
}

bool bfs(vector<vector<Edge>>& graph, int s, int t, vector<int>& level) {
    fill(level.begin(), level.end(), -1);

    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& e : graph[u]) {
            if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }

    return level[t] != -1;
}

ll dfs(vector<vector<Edge>>& graph, int u, int t, ll pushed, vector<int>& level, vector<int>& ptr) {
    if (pushed == 0) return 0;
    if (u == t) return pushed;

    while (ptr[u] < (int)graph[u].size()) {
        Edge& e = graph[u][ptr[u]];

        if (e.cap > 0 && level[e.to] == level[u] + 1) {
            ll flow = dfs(graph, e.to, t, min(pushed, e.cap), level, ptr);

            if (flow) {
                e.cap -= flow;
                graph[e.to][e.rev].cap += flow;
                return flow;
            }
        }

        ptr[u]++;
    }

    return 0;
}

ll max_flow(vector<vector<Edge>>& graph, int s, int t) {
    int n = graph.size();
    ll flow = 0;

    vector<int> level(n);

    while (bfs(graph, s, t, level)) {
        vector<int> ptr(n, 0);

        while (true) {
            ll pushed = dfs(graph, s, t, LLONG_MAX, level, ptr);
            if (pushed == 0) break;

            flow += pushed;
        }
    }

    return flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        edges.pb({a, b});

        add_edge(graph, a, b, 1);
        add_edge(graph, b, a, 1);
    }

    int s = 0;
    int t = n - 1;

    max_flow(graph, s, t);

    vector<bool> visited(n, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& e : graph[u]) {
            if (e.cap > 0 && !visited[e.to]) {
                visited[e.to] = true;
                q.push(e.to);
            }
        }
    }

    vector<pair<int, int>> res;

    for (auto [a, b] : edges) {
        if (visited[a] != visited[b]) {
            res.pb({a + 1, b + 1});
        }
    }

    cout << res.size() << '\n';

    for (auto [a, b] : res) {
        cout << a << ' ' << b << '\n';
    }

    return 0;
}
