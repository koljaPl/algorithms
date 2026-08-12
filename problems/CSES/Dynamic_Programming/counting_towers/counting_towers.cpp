#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 1e9 + 7;
    const int MAX_N = 1000000;

    int t;
    cin >> t;

    vector<int> towers(MAX_N + 1, 0);
    towers[1] = 2;
    towers[2] = 8;

    for (int i = 3; i <= MAX_N; ++i) {
        towers[i] = (
            6LL * towers[i - 1] +
            1LL * (MOD - 7) * towers[i - 2]
        ) % MOD;
    }
    
    while (t--) {
        int n;
        cin >> n;

        cout << towers[n] << "\n";
    }

    return 0;
}
