#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("factory");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        arr[a]++;
    }

    int res = -1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            if (res != -1) {
                cout << -1 << "\n";
                return 0;
            }
            res = i;
        }
    }

    cout << res << "\n";

    return 0;
}
