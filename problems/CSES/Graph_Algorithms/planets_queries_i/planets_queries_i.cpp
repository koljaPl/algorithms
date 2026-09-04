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
    }

    const int LOG = 31;

    vector<vector<int>> up(LOG, vector<int>(n));

    for (int v = 0; v < n; v++) {
        up[0][v] = t[v] - 1;
    }

    for (int j = 1; j < LOG; j++) {
        for (int v = 0; v < n; v++) {
            up[j][v] = up[j - 1][up[j - 1][v]];
        }
    }

    while (q--) {
        int x;
        long long k;

        cin >> x >> k;

        x--;

        for (int j = 0; j < LOG; j++) {
            if (k & (1LL << j)) {
                x = up[j][x];
            }
        }

        cout << x + 1 << '\n';
    }

    return 0;
}
