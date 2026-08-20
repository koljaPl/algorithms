#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    
    vector<int> arr(n);
    vector<ll> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        prefix[i + 1] = prefix[i] + x;
    }

    deque<int> q;
    ll res = LLONG_MIN;

    for (int right = a; right < n + 1; right++) {
        int new_left = right - a;

        while (!q.empty() && prefix[q.back()] >= prefix[new_left])
            q.pop_back();
            
        q.push_back(new_left);

        int min_left = right - b;

        while (!q.empty() && q.front() < min_left) {
            q.pop_front();
        }

        res = max(res, prefix[right] - prefix[q.front()]);
    }

    cout << res << '\n';

    return 0;
}
