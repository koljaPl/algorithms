#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].pb(b);
    }

    vector<int> state(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int cycle_start = -1;
    int cycle_end = -1;

    function<bool(int)> dfs = [&](int u) {
        state[u] = 1;

        for (int v : graph[u]) {
            if (state[v] == 0) {
                parent[v] = u;

                if (dfs(v)) {
                    return true;
                }
            }
            else if (state[v] == 1) {
                cycle_start = v;
                cycle_end = u;

                return true;
            }
        }

        state[u] = 2;

        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (state[i] == 0) {
            if (dfs(i)) {
                break;
            }
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";

        return 0;
    }

    vector<int> cycle = {cycle_start};

    int curr = cycle_end;

    while (curr != cycle_start) {
        cycle.push_back(curr);
        curr = parent[curr];
    }

    cycle.pb(cycle_start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << '\n';

    for (int v : cycle) {
        cout << v << ' ';
    }
    cout << '\n';

    return 0;
}
