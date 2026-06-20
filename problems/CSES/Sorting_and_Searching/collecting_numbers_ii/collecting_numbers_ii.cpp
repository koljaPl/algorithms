#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> list_x(n);
    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> list_x[i];
        pos[list_x[i]] = i;
    }

    int res = 1;
    for (int i = 2; i < n + 1; i++) {
        if (pos[i] < pos[i - 1]) res++;
    }

    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;
        left -= 1;
        right -= 1;

        int x = list_x[left];
        int y = list_x[right];

        set<pair<int, int>> pairs;
        for (int v : {x, y}) {
            if (v > 1) pairs.insert({v - 1, v});
            if (v < n) pairs.insert({v, v + 1});
        }

        for (auto p : pairs) {
            if (pos[p.second] < pos[p.first]) res--;
        }

        swap(list_x[left], list_x[right]);
        pos[x] = right;
        pos[y] = left;

        for (auto p : pairs) {
            if (pos[p.second] < pos[p.first]) res++;
        }

        cout << res << "\n";
    }

    return 0;
}
