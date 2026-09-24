#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

bool isValid(const string& s, int n, int k) {
    unordered_set<string_view> seen;
    string_view sv(s);

    for (int i = 0; i <= n - k; ++i) {
        string_view sub = sv.substr(i, k);
        if (seen.count(sub)) {
            return false;
        }
        seen.insert(sub);
    }

    return true;
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() { 
    setIO("whereami");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    for (int k = 1; k <= n; ++k) {
        if (isValid(s, n, k)) {
            cout << k << "\n";
            break;
        }
    }

    return 0;
}
