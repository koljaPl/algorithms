#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> to;
    vector<ll> cap;

    auto add_edge = [&](int u, int v, ll c) {
        adj[u].push_back((int)to.size());

        to.push_back(v);
        cap.push_back(c);

        adj[v].push_back((int)to.size());

        to.push_back(u);
        cap.push_back(0);
    };

    for (int i = 0; i < m; i++) {
        int u, v;
        ll c;

        cin >> u >> v >> c;

        add_edge(u - 1, v - 1, c);
    }

    int s = 0;
    int t = n - 1;

    vector<int> level(n, -1);
    vector<int> ptr(n, 0);

    auto bfs = [&]() -> bool {
        fill(level.begin(), level.end(), -1);

        level[s] = 0;

        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int e : adj[u]) {
                if (cap[e] == 0) {
                    continue;
                }

                int v = to[e];

                if (level[v] != -1) {
                    continue;
                }

                level[v] = level[u] + 1;
                q.push(v);
            }
        }

        return level[t] != -1;
    };

    function<long long(int, long long)> dfs =
        [&](int u, long long pushed) -> long long {

        if (u == t) {
            return pushed;
        }

        while (ptr[u] < (int)adj[u].size()) {
            int e = adj[u][ptr[u]];
            int v = to[e];

            if (cap[e] > 0 && level[v] == level[u] + 1) {
                long long flow = dfs(v, min(pushed, cap[e]));

                if (flow) {
                    cap[e] -= flow;
                    cap[e ^ 1] += flow;

                    return flow;
                }
            }

            ptr[u]++;
        }

        return 0;
    };

    ll max_flow = 0;
    const ll INF = (ll)1e18;

    while (bfs()) {
        fill(ptr.begin(), ptr.end(), 0);

        while (true) {
            ll pushed = dfs(s, INF);

            if (pushed == 0) {
                break;
            }

            max_flow += pushed;
        }
    }

    cout << max_flow << '\n';

    return 0;
}
