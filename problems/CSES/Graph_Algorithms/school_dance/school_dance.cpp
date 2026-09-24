#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        adj[a].pb(b);
    }

    vector<int> match(m, -1);
    vector<bool> used(n);

    function<bool(int)> dfs = [&](int boy) -> bool {
        if (used[boy]) return false;

        used[boy] = true;

        for (int girl : adj[boy]) {
            if (match[girl] == -1 || dfs(match[girl])) {
                match[girl] = boy;
                return true;
            }
        }

        return false;
    };

    int res = 0;
    for (int boy = 0; boy < n; boy++) {
        fill(used.begin(), used.end(), false);

        if (dfs(boy)) res++;
    }

    cout << res << '\n';
    for (int girl = 0; girl < m; girl++) {
        if (match[girl] != -1) {
            cout << match[girl] + 1 << ' ' << girl + 1 << '\n';
        }
    }

    return 0;
}
