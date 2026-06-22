#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main_v1() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> list_x(n);
    for (int i = 0; i < n; i++) cin >> list_x[i];

    map<int, int> count;
    int left = 0;
    ll res = 0;

    for (int i = 0; i < n; i++) {
        count[list_x[i]] += 1;

        while (count[list_x[i]] > 1) {
            count[list_x[left]] -= 1;
            left += 1;
        }

        res += i - left + 1;
    }

    cout << res << '\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> last_pos;
    int left_pos = 1;
    ll res = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        left_pos = max(left_pos, last_pos[x] + 1);
        res += i - left_pos + 1;
        
        last_pos[x] = i;
    }

    cout << res << "\n";

    return 0;
}
