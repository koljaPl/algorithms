#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    vector<int> degree(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        graph[a].pb({b, i});
        graph[b].pb({a, i});

        degree[a]++;
        degree[b]++;
    }

    for (int v = 0; v < n; v++) {
        if (degree[v] % 2) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<bool> used(m, false);
    vector<int> index(n, 0);

    vector<int> stack = {0};
    vector<int> path;

    while (!stack.empty()) {
        int v = stack.back();

        while (
            index[v] < (int)graph[v].size() &&
            used[graph[v][index[v]].second]
        ) {
            index[v]++;
        }

        if (index[v] == (int)graph[v].size()) {
            path.pb(v);
            stack.pop_back();
        } else {
            auto [u, i] = graph[v][index[v]];

            index[v]++;

            if (!used[i]) {
                used[i] = true;
                stack.pb(u);
            }
        }
    }

    if ((int)path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    reverse(path.begin(), path.end());

    for (int v : path) {
        cout << v + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
