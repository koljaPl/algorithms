#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

struct Segment {
    int length;
    int speed;
};

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("speeding");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Segment> road(n);
    for (int i = 0; i < n; ++i) cin >> road[i].length >> road[i].speed;

    vector<Segment> bessie(m);
    for (int i = 0; i < m; ++i) cin >> bessie[i].length >> bessie[i].speed;

    int i = 0, j = 0;
    int res = 0;

    while (i < n && j < m) {
        res = max(res, bessie[j].speed - road[i].speed);

        int step = min(road[i].length, bessie[j].length);
        road[i].length -= step;
        bessie[j].length -= step;

        if (road[i].length == 0) i++;
        if (bessie[j].length == 0) j++;
    }

    cout << res << '\n';

    return 0;
}
