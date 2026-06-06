#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }

    if (*max_element(freq.begin(), freq.end()) > (n + 1) / 2) {
        cout << "-1\n";
        return 0;
    }

    vector<char> res;
    int prev = -1;

    for (int pos = 0; pos < n; pos++) {
        for (int c = 0; c < 26; c++) {
            if (c == prev || freq[c] == 0) continue;

            freq[c]--;

            int remaining = n - pos - 1;
            int max_freq = *max_element(freq.begin(), freq.end());

            if (max_freq <= (remaining + 1) / 2) {
                res.push_back(char(c + 'A'));
                prev = c;
                break;
            }

            freq[c]++;
        }
    }

    for (char c : res) cout << c;

    cout << "\n";

    return 0;
}
