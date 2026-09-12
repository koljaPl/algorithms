#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("diamond");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
        
    vector<int> arr(n);
    for (int &num : arr) cin >> num;

    sort(arr.begin(), arr.end());

    int res = 0;
    int right = 0;

    for (int left = 0; left < n; left++) {
        while (right < n && arr[right] - arr[left] <= k) {
            right++;
        }
        res = max(res, right - left);
    }

    cout << res << '\n';

    return 0;
}
