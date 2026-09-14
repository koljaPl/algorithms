#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define f first
#define s second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> coins(n);
    for (ll &x : coins) cin >> x;

    vector<vector<int>> graph(n);
    vector<vector<int>> reverse_graph(n);

    vector<pair<int, int>> edges;
    edges.reserve(m);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        graph[a].pb(b);
        reverse_graph[b].pb(a);
        edges.pb({a, b});
    }

    vector<bool> visited(n, false);
    vector<int> order;
    order.reserve(n);

    for (int start = 0; start < n; ++start) {
        if (visited[start]) continue;

        vector<pair<int, int>> stack;
        stack.pb({start, 0});

        visited[start] = true;

        while (!stack.empty()) {
            int node = stack.back().f;
            int index = stack.back().s;

            if (index < (int)graph[node].size()) {
                int neighbor = graph[node][index];

                stack.back().s++;

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.pb({neighbor, 0});
                }
            } else {
                order.pb(node);
                stack.pop_back();
            }
        }
    }

    vector<int> component(n, -1);
    int component_count = 0;

    for (int i = n - 1; i >= 0; --i) {
        int start = order[i];

        if (component[start] != -1) continue;

        vector<int> stack = {start};
        component[start] = component_count;

        while (!stack.empty()) {
            int node = stack.back();
            stack.pop_back();

            for (int neighbor : reverse_graph[node]) {
                if (component[neighbor] == -1) {
                    component[neighbor] = component_count;
                    stack.pb(neighbor);
                }
            }
        }

        component_count++;
    }

    vector<ll> component_coins(component_count, 0);

    for (int node = 0; node < n; ++node)
        component_coins[component[node]] += coins[node];

    vector<vector<int>> dag(component_count);
    vector<int> indegree(component_count, 0);

    for (auto [a, b] : edges) {
        int ca = component[a];
        int cb = component[b];

        if (ca != cb) dag[ca].pb(cb);
    }

    for (int node = 0; node < component_count; ++node) {
        sort(dag[node].begin(), dag[node].end());

        dag[node].erase(
            unique(dag[node].begin(), dag[node].end()),
            dag[node].end()
        );

        for (int neighbor : dag[node]) indegree[neighbor]++;
    }

    vector<int> queue;

    for (int node = 0; node < component_count; ++node) {
        if (indegree[node] == 0)
            queue.pb(node);
    }

    vector<ll> dp = component_coins;

    int index = 0;

    while (index < (int)queue.size()) {
        int node = queue[index++];

        for (int neighbor : dag[node]) {
            dp[neighbor] = max(dp[neighbor], dp[node] + component_coins[neighbor]);

            indegree[neighbor]--;

            if (indegree[neighbor] == 0) queue.pb(neighbor);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
