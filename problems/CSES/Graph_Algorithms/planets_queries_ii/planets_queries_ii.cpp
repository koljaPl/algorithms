#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> t(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
    }

    int LOG = 1;

    while ((1 << LOG) <= n) {
        LOG++;
    }

    vector<vector<int>> up(LOG, vector<int>(n));

    for (int v = 0; v < n; v++) {
        up[0][v] = t[v];
    }

    for (int j = 1; j < LOG; j++) {
        for (int v = 0; v < n; v++) {
            up[j][v] = up[j - 1][up[j - 1][v]];
        }
    }

    auto jump = [&](int v, int k) {
        int j = 0;

        while (k) {
            if (k & 1) {
                v = up[j][v];
            }

            k >>= 1;
            j++;
        }

        return v;
    };

    vector<vector<int>> reverse_graph(n);
    vector<int> indegree(n, 0);

    for (int v = 0; v < n; v++) {
        int u = t[v];

        reverse_graph[u].push_back(v);
        indegree[u]++;
    }

    queue<int> queue;

    for (int v = 0; v < n; v++) {
        if (indegree[v] == 0) {
            queue.push(v);
        }
    }

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();

        int u = t[v];

        indegree[u]--;

        if (indegree[u] == 0) {
            queue.push(u);
        }
    }

    vector<int> cycle_id(n, -1);
    vector<int> cycle_pos(n, -1);

    vector<int> cycle_len;

    vector<bool> visited(n, false);

    int cid = 0;

    for (int start = 0; start < n; start++) {
        if (indegree[start] == 0 || visited[start]) {
            continue;
        }

        int curr = start;
        int pos = 0;

        while (!visited[curr]) {
            visited[curr] = true;

            cycle_id[curr] = cid;
            cycle_pos[curr] = pos;

            pos++;
            curr = t[curr];
        }

        cycle_len.push_back(pos);
        cid++;
    }

    vector<int> depth(n, -1);
    vector<int> entry(n, -1);

    while (!queue.empty()) {
        queue.pop();
    }

    for (int v = 0; v < n; v++) {
        if (indegree[v] > 0) {
            depth[v] = 0;
            entry[v] = v;
            queue.push(v);
        }
    }

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (int v : reverse_graph[u]) {
            if (depth[v] != -1) {
                continue;
            }

            depth[v] = depth[u] + 1;
            entry[v] = entry[u];
            cycle_id[v] = cycle_id[u];

            queue.push(v);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        if (cycle_id[a] != cycle_id[b]) {
            cout << -1 << '\n';
            continue;
        }

        if (depth[b] > 0) {
            if (depth[a] < depth[b]) {
                cout << -1 << '\n';
                continue;
            }

            int dist = depth[a] - depth[b];

            if (jump(a, dist) == b) {
                cout << dist << '\n';
            } else {
                cout << -1 << '\n';
            }

        } else {
            int start_cycle = entry[a];

            int cid = cycle_id[a];
            int length = cycle_len[cid];

            int cycle_dist =
                (cycle_pos[b] - cycle_pos[start_cycle] + length) % length;

            int res = depth[a] + cycle_dist;

            cout << res << '\n';
        }
    }

    return 0;
}
