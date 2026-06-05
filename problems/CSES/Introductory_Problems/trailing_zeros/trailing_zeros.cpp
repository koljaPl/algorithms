#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll  n = 1;
    cin >> n;

    ll zeroes = 0;
    ll divider = 5;

    while (n >= divider) {
        zeroes += n / divider;
        divider *= 5;
    }

    cout << zeroes;

    return 0;
}
