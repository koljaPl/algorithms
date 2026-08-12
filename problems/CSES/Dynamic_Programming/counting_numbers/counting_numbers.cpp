#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string digits;
ll memo[20][11][2][2];
bool visited[20][11][2][2];

ll dp(int pos, int previous, bool tight, bool started) {
    if (pos == digits.size()) {
        return 1;
    }

    if (visited[pos][previous][tight][started]) {
        return memo[pos][previous][tight][started];
    }

    visited[pos][previous][tight][started] = true;

    int currentDigit = digits[pos] - '0';
    int limit = tight ? currentDigit : 9;

    ll res = 0;

    for (int digit = 0; digit <= limit; digit++) {
        bool nextTight = tight && (digit == currentDigit);

        if (!started && digit == 0) {
            res += dp(
                pos + 1,
                10,
                nextTight,
                false
            );

            continue;
        }

        if (started && digit == previous) {
            continue;
        }

        res += dp(
            pos + 1,
            digit,
            nextTight,
            true
        );
    }

    return memo[pos][previous][tight][started] = res;
}

ll count_valid(ll x) {
    if (x < 0) {
        return 0;
    }

    digits = to_string(x);

    memset(visited, false, sizeof(visited));

    return dp(0, 10, true, false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;

    cout << count_valid(b) - count_valid(a - 1) << '\n';

    return 0;
}
