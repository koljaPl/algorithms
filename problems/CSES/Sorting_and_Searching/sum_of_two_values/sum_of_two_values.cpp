#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; 
    }

    sort(a.begin(), a.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        ll current_sum = (ll)a[left].first + a[right].first;

        if (current_sum == x) {
            cout << a[left].second << " " << a[right].second << "\n";
            return 0;
        } else if (current_sum < x) {
            left++;
        } else {
            right--;
        }
    }

    cout << "IMPOSSIBLE\n";
    
    return 0;
}
