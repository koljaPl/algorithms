#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll w;

        cin >> a >> b >> w;

        graph[a - 1].push_back({b - 1, w});
    }

    vector<int> count(n, 0);

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    vector<ll> res;

    pq.push({0, 0});
    
    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (count[u] >= k)
            continue;

        count[u]++;

        if (u == n - 1) {
            res.push_back(cost);

            if ((int)res.size() == k)
                break;
        }

        for (auto [v, w] : graph[u]) {
            if (count[v] < k) {
                pq.push({cost + w, v});
            }
        }
    }

    for (ll num : res)
        cout << num << ' ';

    cout << '\n';

    return 0;
}
