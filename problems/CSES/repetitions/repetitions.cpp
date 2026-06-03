#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dna;
    cin >> dna;

    ll res = 1;
    ll curr = 1;
    for (ll i = 1; i < dna.size(); i++) {
        if (dna[i] == dna[i - 1]) {
            curr++;
        } else {
            curr = 1;
        }

        res = max(res, curr);
    }

    cout << res << "\n";

    return 0;
}
