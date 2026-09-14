#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(2 * m);
    vector<vector<int>> reverse_graph(2 * m);

    auto get_node = [&](char sign, int x) {
        x--;

        if (sign == '+') {
            return 2 * x;
        } else {
            return 2 * x + 1;
        }
    };

    auto add_edge = [&](int u, int v) {
        graph[u].pb(v);
        reverse_graph[v].pb(u);
    };

    for (int i = 0; i < n; ++i) {
        char s1, s2;
        int x1, x2;

        cin >> s1 >> x1 >> s2 >> x2;

        int a = get_node(s1, x1);
        int b = get_node(s2, x2);

        add_edge(a ^ 1, b);
        add_edge(b ^ 1, a);
    }

    vector<bool> visited(2 * m, false);
    vector<int> order;

    for (int start = 0; start < 2 * m; ++start) {
        if (visited[start]) {
            continue;
        }

        vector<pair<int, int>> stack;
        stack.push_back({start, 0});

        visited[start] = true;

        while (!stack.empty()) {
            int v = stack.back().first;
            int i = stack.back().second;

            if (i < (int)graph[v].size()) {
                int to = graph[v][i];

                stack.back().second++;

                if (!visited[to]) {
                    visited[to] = true;
                    stack.pb({to, 0});
                }
            } else {
                order.pb(v);
                stack.pop_back();
            }
        }
    }

    vector<int> component(2 * m, -1);
    int component_id = 0;

    for (auto it = order.rbegin(); it != order.rend(); ++it) {
        int start = *it;

        if (component[start] != -1) {
            continue;
        }

        vector<int> stack = {start};
        component[start] = component_id;

        while (!stack.empty()) {
            int v = stack.back();
            stack.pop_back();

            for (int to : reverse_graph[v]) {
                if (component[to] == -1) {
                    component[to] = component_id;
                    stack.pb(to);
                }
            }
        }

        component_id++;
    }

    vector<char> res;

    for (int i = 0; i < m; ++i) {
        int positive = 2 * i;
        int negative = positive + 1;

        if (component[positive] == component[negative]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        if (component[positive] > component[negative]) {
            res.pb('+');
        } else {
            res.pb('-');
        }
    }

    for (char sign : res) {
        cout << sign << ' ';
    }
    cout << '\n';

    return 0;
}
