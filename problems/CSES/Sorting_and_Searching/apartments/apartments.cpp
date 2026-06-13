#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> list_a(n);
    vector<int> list_b(m);

    for (int i = 0; i < n; i++) {
        cin >> list_a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> list_b[i];
    }

    sort(list_a.begin(), list_a.end());
    sort(list_b.begin(), list_b.end());

    int res = 0;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (list_b[j] < list_a[i] - k) {
            j += 1;
        } else if (list_b[j] > list_a[i] + k) {
            i += 1;
        } else {
            res += 1;
            i += 1;
            j += 1;
        }
    }

    cout << res << "\n";
    
    return 0;
}
