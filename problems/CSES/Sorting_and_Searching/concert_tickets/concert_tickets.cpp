#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tickets.insert(x);
    }

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;

        auto it = tickets.upper_bound(x);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            it--;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }

    return 0;
}
