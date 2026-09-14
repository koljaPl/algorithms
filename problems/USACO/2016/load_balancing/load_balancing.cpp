#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define f first
#define s second

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("balancing");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    cin >> n >> b;
        
    vector<pair<int, int>> cows(n);
    vector<int> x_divs, y_divs;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].f >> cows[i].s;

        x_divs.pb(cows[i].f + 1);
        y_divs.pb(cows[i].s + 1);
    }

    int res = n;

    for (int a : x_divs) {
        for (int b_val : y_divs) {
            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;

            for (const auto& [x, y] : cows) {
                if (x > a && y > b_val) q1++;
                else if (x < a && y > b_val) q2++;
                else if (x < a && y < b_val) q3++;
                else if (x > a && y < b_val) q4++;
            }

            int curr_max = max({q1, q2, q3, q4});
            res = min(res, curr_max);
        }
    }

    cout << res << "\n";

    return 0;
}
