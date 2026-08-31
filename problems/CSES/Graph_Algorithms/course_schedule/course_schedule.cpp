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

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a - 1].pb(b - 1);
    }

    vector<int> res;

    unordered_set<int> visited;
    unordered_set<int> cycle;

    function<bool(int)> dfs = [&](int course) {
        if (cycle.count(course)) {
            return false;
        }

        if (visited.count(course)) {
            return true;
        }

        cycle.insert(course);

        for (int nxt : graph[course]) {
            if (!dfs(nxt)) {
                return false;
            }
        }

        cycle.erase(course);

        visited.insert(course);

        res.pb(course);

        return true;
    };

    for (int i = 0; i < n; i++) {
        if (!visited.count(i)) {
            if (!dfs(i)) {
                cout << "IMPOSSIBLE\n";

                return 0;
            }
        }
    }

    reverse(res.begin(), res.end());

    for (int x : res) {
        cout << x + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
