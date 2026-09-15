#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// https://codeforces.com/gym/102951/problem/A

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
	cin >> n;
	vector<int> x(n), y(n);

	for (int &num : x) cin >> num;
	for (int &num : y) cin >> num;

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			int square = dx * dx + dy * dy;

			res = max(res, square);
		}
	}

	cout << res << "\n";

    return 0;
}
