#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(ll k, ll x) {
    ll dist_up = 0;
    ll dist_down = 0;
    ll time = 0;

    for (ll speed = 1; ; speed++) {
        dist_up += speed;
        time++;
        if (dist_up + dist_down >= k) {
            cout << time << "\n";
            return;
        }

        if (speed >= x) {
            dist_down += speed;
            time++;
            if (dist_up + dist_down >= k) {
                cout << time << "\n";
                return;
            }
        }
    }

    return;
}

int main() {
    setIO("race");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k;
    int n;
    cin >> k >> n;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        solve(k, x);
    }

    return 0;
}
