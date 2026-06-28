#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll, ll>> tasks(n);
    for (int i = 0; i < n; i++)
        cin >> tasks[i].first >> tasks[i].second;
        
    sort(tasks.begin(), tasks.end());
    
    ll time = 0;
    ll res = 0;

    for (const auto& [a, d] : tasks) {
        time += a;
        res += d - time;
    }

    cout << res << "\n";

    return 0;
}
