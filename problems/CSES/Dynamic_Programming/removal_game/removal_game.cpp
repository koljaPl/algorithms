#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<long long> dp = arr;

    for (int length = 2; length <= n; length++) {
        for (int left = 0; left + length - 1 < n; left++) {
            long long right = left + length - 1;

            long long take_left = arr[left] - dp[left + 1];
            long long take_right = arr[right] - dp[left];

            dp[left] = max(take_left, take_right);
        }
    }
    
    long long total_sum = accumulate(arr.begin(), arr.end(), 0LL);
    long long difference = dp[0];

    cout << (total_sum + difference) / 2 << "\n";

    return 0;
}
