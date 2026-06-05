#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int n;
vector<bool> used;
vector<string> res;
string curr;

void backtracking() {
    if ((int)curr.size() == n) {
        res.push_back(curr);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

        used[i] = true;
        curr.push_back(s[i]);

        backtracking();

        curr.pop_back();
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.size();

    sort(s.begin(), s.end());

    used.assign(n, false);

    backtracking();

    cout << res.size() << "\n";
    for (auto &x : res) {
        cout << x << "\n";
    }

    return 0;
}
