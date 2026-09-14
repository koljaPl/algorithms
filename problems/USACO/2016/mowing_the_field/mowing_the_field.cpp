#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("mowing");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<pair<int, int>, int> last_visit;

    int x = 0, y = 0;
    int t = 0;
    last_visit[{x, y}] = 0;

    int res = 1e9;

    for (int i = 0; i < n; ++i) {
        char dir;
        int steps;
        cin >> dir >> steps;

        int dx = 0, dy = 0;
        if (dir == 'N') dy = 1;
        else if (dir == 'S') dy = -1;
        else if (dir == 'E') dx = 1;
        else if (dir == 'W') dx = -1;

        for (int s = 0; s < steps; ++s) {
            x += dx;
            y += dy;
            t++;

            if (last_visit.count({x, y})) {
                res = min(res, t - last_visit[{x, y}]);
            }

            last_visit[{x, y}] = t;
        }
    }

    if (res == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << res << '\n';
    }

    return 0;
}
