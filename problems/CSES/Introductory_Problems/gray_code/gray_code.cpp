#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    vector<string> gray = {""};

    for (int i = 0; i < n; i++) {
        vector<string> next;
        
        next.reserve(gray.size() * 2);

        for (auto &x : gray)
            next.push_back("0" + x);

        for (auto it = gray.rbegin(); it != gray.rend(); ++it)
            next.push_back("1" + *it);

        gray = move(next);
    }

    for (auto &s : gray)
        cout << s << "\n";

    return 0;
}
