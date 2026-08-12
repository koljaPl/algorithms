#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, money;
    cin >> n >> money;

    vector<int> prices(n);
    vector<int> pages(n);

    for (int& price : prices) {
        cin >> price;
    }

    for (int& page : pages) {
        cin >> page;
    }

    vector<int> dp(money + 1, 0);

    for (int i = 0; i < n; ++i) {
        int currPrice = prices[i];
        int currPages = pages[i];

        for (int x = money; x >= currPrice; --x) {
            dp[x] = max(
                dp[x],
                dp[x - currPrice] + currPages
            );
        }
    }

    cout << dp[money] << '\n';

    return 0;
}
