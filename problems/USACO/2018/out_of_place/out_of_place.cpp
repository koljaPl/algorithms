#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("outofplace");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != sorted_arr[i]) {
            res++;
        }
    }

    cout << max(0, res - 1) << "\n";

    return 0;
}
