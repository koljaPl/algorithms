#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ps(n);
    for (int &p : ps) cin >> p;

    int res = 0;
    for (int left = 0; left < n; left ++) {
        int total_sum = 0;
        unordered_set<int> nums;

        for (int right = left; right < n; right ++) {
            total_sum += ps[right];
            nums.insert(ps[right]);

            int len = right - left + 1;

            if (total_sum % len == 0) {
                int avg = total_sum / len;

                if (nums.count(avg)) {
                    res++;
                }
            }
        }
    }

    cout << res << "\n";

    return 0;
}
