#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if ((a + b > n) || (((a == 0) != (b == 0)))) {
        cout << "NO\n" << "\n";
        return;
    }

    int draws = n - (a + b);
        
    vector<int> p1;
    vector<int> p2;

    for (int i = 1; i <= n; i++) {
        p1.push_back(i);
    }

    for (int i = 1; i <= draws; i++) {
        p2.push_back(i);
    }

    for (int i = draws + a + 1; i <= n; i++) {
        p2.push_back(i);
    }

    for (int i = draws + 1; i <= draws + a; i++) {
        p2.push_back(i);
    }

    cout << "YES\n";

    for (int x : p1) {
        cout << x << ' ';
    }
    cout << '\n';

    for (int x : p2) {
        cout << x << ' ';
    }
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
