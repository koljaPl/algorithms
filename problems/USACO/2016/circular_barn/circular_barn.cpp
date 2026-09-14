#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("cbarn");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    int min_dist = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int current_dist = 0;

        for (int d = 0; d < n; ++d) {
            int room = (i + d) % n;
            current_dist += d * r[room];
        }

        min_dist = min(min_dist, current_dist);
    }

    cout << min_dist << '\n';

    return 0;
}
