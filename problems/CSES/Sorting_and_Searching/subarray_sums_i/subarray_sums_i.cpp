#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll sum = 0;
    ll res = 0;

    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum > target) {
            sum -= arr[left];
            left++;
        }

        if (sum == target)
            res += 1;
    }

    cout << res << "\n";

    return 0;
}
