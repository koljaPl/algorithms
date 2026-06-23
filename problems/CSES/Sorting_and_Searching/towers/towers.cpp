#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> cubes(n);
    for (int i = 0; i < n; i++) cin >> cubes[i];

    vector<ll> tops;
    for (ll cube : cubes) {
        size_t pos = upper_bound(tops.begin(), tops.end(), cube) - tops.begin();

        if (pos == tops.size()) {
            tops.push_back(cube);
        } else {
            tops[pos] = cube;
        }
    }

    cout << tops.size() << "\n";

    return 0;
}
