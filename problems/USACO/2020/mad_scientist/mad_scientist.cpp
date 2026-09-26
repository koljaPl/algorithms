#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("breedflip");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;

    int res = 0;
    int curr = 0;
    for (size_t i = 0; i < n; i++) {
        if (a[i] != b[i]) curr++;
        else if (curr != 0) {
            res++;
            curr = 0;
        }
    }

    cout << res << "\n";

    return 0;
}
