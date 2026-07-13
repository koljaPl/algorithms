#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    map<int, int> prev;
    set<pair<int, int>> rank;

    ll res = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        rank.erase({prev[x], x});
        rank.insert({i, x});

        prev[x] = i;

        if (rank.size() > k + 1) {
            rank.erase(rank.begin());
        }

        if (rank.size() <= k)
            res += i;
        else
            res += i - rank.begin()->first;
    }

    cout << res << "\n";

    return 0;
}
