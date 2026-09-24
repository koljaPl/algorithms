#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("herding");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr(3);
	for (int &b : arr) cin >> b;

	sort(arr.begin(), arr.end());
	
	if (arr[0] == arr[2] - 2) {
		cout << 0 << "\n";
	} else if ((arr[1] == arr[2] - 2) || (arr[0] == arr[1] - 2)) {
		cout << 1 << "\n";
	} else {
		cout << 2 << "\n";
	}

	cout << max(arr[2] - arr[1], arr[1] - arr[0]) - 1;

    return 0;
}
