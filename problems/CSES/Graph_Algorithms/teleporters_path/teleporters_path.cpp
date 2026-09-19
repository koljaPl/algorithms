#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        graph[a].pb(b);
        outdegree[a]++;
        indegree[b]++;
    }

    if (outdegree[0] != indegree[0] + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    if (indegree[n - 1] != outdegree[n - 1] + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int v = 1; v < n - 1; v++) {
        if (indegree[v] != outdegree[v]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<int> stack = {0};
    vector<int> path;

    while (!stack.empty()) {
        int v = stack.back();

        if (!graph[v].empty()) {
            int u = graph[v].back();
            graph[v].pop_back();

            stack.pb(u);
        } else {
            path.pb(stack.back());
            stack.pop_back();
        }
    }

    reverse(path.begin(), path.end());

    if ((int)path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    if (path.front() != 0 || path.back() != n - 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int v : path) {
        cout << v + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
