#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main_v1() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> s;
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << "\n";

    return 0;
}

// Slightly faster than the set version, but uses more memory in the worst case (if all numbers are distinct)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int res = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            res++;
        }
    }

    cout << res << '\n';

    return 0;
}
