#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("pails");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, m;
    cin >> x >> y >> m;

    int max_milk = 0;

    for (int a = 0; a * x <= m; ++a) {
        int b = (m - a * x) / y;
        int current_total = a * x + b * y;
        max_milk = max(max_milk, current_total);
    }

    cout << max_milk << '\n';

    return 0;
}
