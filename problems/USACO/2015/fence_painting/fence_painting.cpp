#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("paint");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
	cin >> a >> b >> c >> d;

	vector<bool> painted(100 + 1);
	for (int i = a; i < b; i++) painted[i] = true;
	for (int i = c; i < d; i++) painted[i] = true;

	int res = 0;
	for (bool i : painted) res += i;

	cout << res << "\n";

    return 0;
}
