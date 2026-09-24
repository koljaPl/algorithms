#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

vector<bool> bfs(int start, const vector<vector<int>>& graph) {
    int n = graph.size();

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return visited;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<vector<int>> reverse_graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }

    vector<bool> visited = bfs(0, graph);

    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            cout << "NO\n";
            cout << 1 << ' ' << v + 1 << '\n';
            return 0;
        }
    }

    vector<bool> visited_reverse = bfs(0, reverse_graph);

    for (int v = 0; v < n; v++) {
        if (!visited_reverse[v]) {
            cout << "NO\n";
            cout << v + 1 << ' ' << 1 << '\n';
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
