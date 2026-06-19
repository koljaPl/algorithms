#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main_v1() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; cin >> n;
    vector<ll> list_a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> list_a[i];
    }
 
    ll curr = list_a[0], res = list_a[0];
 
    for (int i = 1; i < n; i++) {
        curr = max(list_a[i], curr + list_a[i]);
        res = max(res, curr);
    }
 
    cout << res << "\n";
 
    return 0;
}

int main_v2() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; cin >> n;
 
    ll curr, res;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cin >> curr;
            res = curr;
        } else {
            ll i; cin >> i;
            curr = max(i, curr + i);
            res = max(res, curr);
        }
    }
 
    cout << res << "\n";

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    ll val;
    cin >> val;
    ll curr = val, res = val;
    for (int i = 1; i < n; i++) {
        cin >> val;
        curr = max(val, curr + val);
        res = max(res, curr);
    }

    cout << res << "\n";

    return 0;
}
