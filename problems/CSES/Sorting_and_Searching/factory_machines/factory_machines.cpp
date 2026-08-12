#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll t;
    cin >> n >> t;

    ll best_machine = 0;

    vector<ll> machines(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        machines[i] = x;
        best_machine = max(best_machine, x);
    }
    
    ll left = 0;
    ll right = best_machine * t;

    while (left < right) {
        ll mid = left + (right- left) / 2;

        ll count = 0;
        for (ll machine : machines) {
            count += mid / machine;

            if (count > t) break;
        }

        if (count >= t) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << "\n";

    return 0;
}
