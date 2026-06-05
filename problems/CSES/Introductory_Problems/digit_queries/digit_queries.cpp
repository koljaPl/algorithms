#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;

        ll d = 1, count = 9;
        while (k > d * count) {
            k -= d * count;
            d++;
            count *= 10;
        }

        ll start = pow(10, d - 1);
        ll number = start + (k - 1) / d;

        ll digit_index = (k - 1) % d;
        cout << to_string(number)[digit_index] << "\n";
    }

    return 0;
}
