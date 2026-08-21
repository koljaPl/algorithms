#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> team(n + 1, 0);

    for (int start = 1; start <= n; start++) {
        if (team[start] != 0) {
            continue;
        }

        team[start] = 1;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nei : graph[node]) {
                if (team[nei] == 0) {
                    team[nei] = 3 - team[node];
                    q.push(nei);
                }
                else if (team[nei] == team[node]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << team[i] << " ";
    }

    cout << '\n';

    return 0;
}
