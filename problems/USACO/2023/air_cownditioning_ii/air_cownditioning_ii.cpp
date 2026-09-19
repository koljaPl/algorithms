#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

struct Vent {
    int a, b, p, m;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> req(101, 0);
    for (int i = 0; i < n; ++i) {
        int s, t, c;
        cin >> s >> t >> c;

        for (int stall = s; stall <= t; ++stall) req[stall] = c;
    }

    vector<Vent> vents(m);
    for (int i = 0; i < m; ++i) {
        cin >> vents[i].a >> vents[i].b >> vents[i].p >> vents[i].m;
    }

    int res = 1e9;
    for (int mask = 0; mask < (1 << m); ++mask) {
        int current_cost = 0;
        vector<int> cooling(101, 0);

        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                current_cost += vents[i].m;
                for (int stall = vents[i].a; stall <= vents[i].b; ++stall) {
                    cooling[stall] += vents[i].p;
                }
            }
        }

        bool valid = true;
        for (int stall = 1; stall <= 100; ++stall) {
            if (cooling[stall] < req[stall]) {
                valid = false;
                break;
            }
        }

        if (valid) res = min(res, current_cost);
    }

    cout << res << "\n";

    return 0;
}
