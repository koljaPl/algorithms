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
    vector<vector<int>> rev(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        graph[a].pb(b);
        rev[b].pb(a);
    }

    vector<bool> visited(n, false);
    vector<int> order;
    order.reserve(n);

    for (int start = 0; start < n; ++start) {
        if (visited[start])
            continue;

        vector<pair<int, int>> stack;
        stack.pb({start, 0});

        while (!stack.empty()) {
            auto [v, state] = stack.back();
            stack.pop_back();

            if (state == 1) {
                order.pb(v);
                continue;
            }

            if (visited[v])
                continue;

            visited[v] = true;

            stack.pb({v, 1});

            for (int u : graph[v]) {
                if (!visited[u]) {
                    stack.pb({u, 0});
                }
            }
        }
    }

    vector<int> kingdom(n, 0);

    int k = 0;

    for (auto it = order.rbegin(); it != order.rend(); ++it) {
        int start = *it;

        if (kingdom[start] != 0)
            continue;

        k++;

        vector<int> stack;
        stack.push_back(start);

        kingdom[start] = k;

        while (!stack.empty()) {
            int v = stack.back();
            stack.pop_back();

            for (int u : rev[v]) {
                if (kingdom[u] == 0) {
                    kingdom[u] = k;
                    stack.pb(u);
                }
            }
        }
    }

    cout << k << '\n';

    for (int x : kingdom) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
