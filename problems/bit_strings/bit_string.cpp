#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n = 1;
    cin >> n;

    cout << power(2, n, 1000000007) << "\n";
    // or just pow(2, n) % 1000000007, but the above is more efficient for large n

    return 0;
}
