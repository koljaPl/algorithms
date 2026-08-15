#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    const long long INF = 4e18;

    vector<vector<long long>> dist(
        n,
        vector<long long>(n, INF)
    );

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;

        cin >> a >> b >> c;

        --a;
        --b;

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                );
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        --a;
        --b;

        if (dist[a][b] == INF) {
            cout << -1 << '\n';
        } else {
            cout << dist[a][b] << '\n';
        }
    }

    return 0;
}
