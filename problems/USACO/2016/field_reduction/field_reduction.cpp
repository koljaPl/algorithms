#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct Cow {
    int x, y, id;
};

int main() {
    setIO("reduce");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Cow> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].y;
        cows[i].id = i;
    }

    vector<Cow> by_x = cows;
    sort(by_x.begin(), by_x.end(), [](const Cow& a, const Cow& b) {
        return a.x < b.x;
    });

    vector<Cow> by_y = cows;
    sort(by_y.begin(), by_y.end(), [](const Cow& a, const Cow& b) {
        return a.y < b.y;
    });

    set<int> candidates = {
        by_x.front().id, by_x.back().id,
        by_y.front().id, by_y.back().id
    };

    ll min_area = LLONG_MAX;

    for (int removed_id : candidates) {
        int min_x = (by_x[0].id == removed_id) ? by_x[1].x : by_x[0].x;
        int max_x = (by_x[n - 1].id == removed_id) ? by_x[n - 2].x : by_x[n - 1].x;
        
        int min_y = (by_y[0].id == removed_id) ? by_y[1].y : by_y[0].y;
        int max_y = (by_y[n - 1].id == removed_id) ? by_y[n - 2].y : by_y[n - 1].y;

        ll area = 1LL * (max_x - min_x) * (max_y - min_y);
        min_area = min(min_area, area);
    }

    cout << min_area << '\n';

    return 0;
}
