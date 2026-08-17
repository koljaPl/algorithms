#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);

    vector<bool> visited(n + 1, false);
    visited[1] = true;

    vector<int> parent(n + 1, -1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int nei : graph[node]) {
            if (!visited[nei]) {
                visited[nei] = true;
                parent[nei] = node;
                q.push(nei);
            }
        }
    }

    if (!visited[n]) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        vector<int> path;

        int node = n;
        while (node != -1) {
            path.push_back(node);
            node = parent[node];
        }

        reverse(path.begin(), path.end());

        cout << path.size() << '\n';

        for (auto num : path) cout << num << "\n";
    }

    return 0;
}
