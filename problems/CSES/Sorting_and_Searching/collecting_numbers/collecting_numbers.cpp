#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> pos(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }

    int res = 1;
    for (int i = 2; i < n + 1; i++) {
        if (pos[i] < pos[i - 1]) res++;
    }

    cout << res << "\n";

    return 0;
}
