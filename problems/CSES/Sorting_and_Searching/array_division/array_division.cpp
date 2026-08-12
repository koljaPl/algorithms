#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);

    for (ll& x : arr) cin >> x;

    auto canDivide = [&](ll limit) {
        int parts = 1;
        ll currentSum = 0;

        for (ll x : arr) {
            if (currentSum + x <= limit) {
                currentSum += x;
            } else {
                parts++;
                currentSum = x;

                if (parts > k) {
                    return false;
                }
            }
        }

        return true;
    };

    ll left = *max_element(arr.begin(), arr.end());
    ll right = accumulate(arr.begin(), arr.end(), 0LL);

    while (left < right) {
        ll mid = left + (right - left) / 2;

        if (canDivide(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << '\n';

    return 0;
}
