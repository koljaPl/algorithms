#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main_v1() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, target;
    cin >> n >> target;
    
    vector<ll> arr;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
 
        arr.push_back(x);
    }
 
    map<ll, ll> count;
    count[0] = 1;
 
    ll prefix_sum = 0;
    ll res = 0;
 
    for (int x : arr) {
        prefix_sum += x;
 
        res += count[prefix_sum - target];
        
        count[prefix_sum]++;
    }
 
    cout << res << "\n";
 
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    map<ll, int> sums;
    sums[0] = 1;

    ll sum = 0;
    ll count = 0;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        sum += a;

        count += sums[sum - target];

        sums[sum]++;
    }

    cout << count << "\n";

    return 0;
}
