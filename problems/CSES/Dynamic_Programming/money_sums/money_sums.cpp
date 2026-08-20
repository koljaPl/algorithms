#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main_v1() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coins(n);

    int total_sum = 0;

    for (int& coin : coins) {
        cin >> coin;
        total_sum += coin;
    }

    bitset<100001> dp;
    dp[0] = 1;

    for (int coin : coins) {
        dp |= dp << coin;
    }

    vector<int> res;

    for (int sum = 1; sum <= total_sum; ++sum) {
        if (dp[sum]) {
            res.push_back(sum);
        }
    }

    cout << res.size() << "\n";

    for (int sum : res) cout << sum << " ";

    cout << '\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coins(n);
    bitset<100001> dp;
    dp[0] = 1;

    int total_sum = 0;

    for (int& coin : coins) {
        cin >> coin;

        total_sum += coin;

        dp |= dp << coin;
    }

    vector<int> res;

    for (int sum = 1; sum <= total_sum; ++sum) {
        if (dp[sum]) {
            res.push_back(sum);
        }
    }

    cout << res.size() << "\n";

    for (int sum : res) cout << sum << " ";

    cout << '\n';

    return 0;
}