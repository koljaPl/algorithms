#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    string left_part = "";
    string mid = "";

    for (char c = 'A'; c <= 'Z'; c++) {
        int cnt = freq[c - 'A'];

        if (cnt == 0) continue;

        if (cnt % 2 == 1) {
            if (!mid.empty()) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            mid = c;
        }

        left_part.append(cnt / 2, c);
    }

    string right_part = left_part;
    reverse(right_part.begin(), right_part.end());

    cout << left_part << mid << right_part << "\n";

    return 0;
}
