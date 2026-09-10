#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Z-Algorithm:
// Time Complexity:
// O(n)
//
// Space Complexity:
// O(n)

vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);

    int l = 0;
    int r = 0;

    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}

// Usage:

vector<int> find_pattern(const string& text, const string& pattern) {
    string s = pattern + "#" + text;

    vector<int> z = z_function(s);
    vector<int> result;

    for (int i = pattern.size() + 1; i < (int)s.size(); ++i) {
        if (z[i] == (int)pattern.size()) {
            result.pb(i - pattern.size() - 1);
        }
    }

    return result;
}

int main() {
    vector<int> result = find_pattern("abacaba", "aba");

    for (int pos : result) {
        cout << pos << ' ';
    }

    cout << '\n';
}
// [0, 4]
