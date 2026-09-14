#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("angry");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int res = 0;

    for (int i = 0; i < n; i++) {
        int left_idx = i;
        int radius = 1;

        while (left_idx > 0) {
            int next_left = left_idx;

            while (next_left - 1 >= 0 && arr[left_idx] - arr[next_left - 1] <= radius) {
                next_left--;
            }

            if (next_left == left_idx) break;

            left_idx = next_left;
            radius++;
        }

        int right_idx = i;
        radius = 1;
        
        while (right_idx < n - 1) {
            int next_right = right_idx;

            while (next_right + 1 < n && arr[next_right + 1] - arr[right_idx] <= radius) {
                next_right++;
            }

            if (next_right == right_idx) break;

            right_idx = next_right;
            radius++;
        }

        res = max(res, right_idx - left_idx + 1);
    }

    cout << res << "\n";

    return 0;
}
