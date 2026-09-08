#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

struct Drink {
    int p, m, t;
};

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("badmilk");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, d, s;
    cin >> n >> m >> d >> s;

    vector<Drink> drinks(d);
    for (int i = 0; i < d; ++i) {
        cin >> drinks[i].p >> drinks[i].m >> drinks[i].t;
    }

    vector<int> sick_time(n + 1, 0);
    for (int i = 0; i < s; ++i) {
        int p, t;
        cin >> p >> t;
        sick_time[p] = t;
    }

    int res = 0;
    for (int milk = 1; milk <= m; ++milk) {
        bool possible = true;

        for (int p = 1; p <= n; ++p) {
            if (sick_time[p] == 0) continue;

            bool drank_before = false;
            for (const auto& drink : drinks) {
                if (drink.p == p && drink.m == milk && drink.t < sick_time[p]) {
                    drank_before = true;
                    break;
                }
            }

            if (!drank_before) {
                possible = false;
                break;
            }
        }

        if (possible) {
            vector<bool> drank(n + 1, false);
            int count = 0;
            for (const auto& drink : drinks) {
                if (drink.m == milk && !drank[drink.p]) {
                    drank[drink.p] = true;
                    count++;
                }
            }
            res = max(res, count);
        }
    }

    cout << res << '\n';

    return 0;
}
