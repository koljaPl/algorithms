#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> arr;
    for (int i = 0; i < n; i += 2) {
        if (s[i] == 'G' && s[i + 1] == 'H') {
            arr.pb(0);
        } else if (s[i] == 'H' && s[i + 1] == 'G') {
            arr.pb(1);
        }
    }

    int res = 0;
    int target = 1;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] != target) {
            res++;
            target = arr[i];
        }
    }

    cout << res << "\n";

    return 0;
}
