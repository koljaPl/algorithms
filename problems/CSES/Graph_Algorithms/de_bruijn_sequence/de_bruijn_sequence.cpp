#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void solve() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "01\n";
        return 0;
    }

    int size = 1 << (n - 1);
    int mask = size - 1;

    vector<int> used(size, 0);
    string res;

    function<void(int)> dfs = [&](int v) {
        while (used[v] < 2) {
            int bit = used[v];
            ++used[v];

            int u = ((v << 1) | bit) & mask;

            dfs(u);
            res.push_back('0' + bit);
        }
    };

    dfs(0);

    reverse(res.begin(), res.end());

    cout << string(n - 1, '0') << res << '\n';

    return 0;
}
