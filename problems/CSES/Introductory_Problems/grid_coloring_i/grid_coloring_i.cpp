#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    string letters = "ABCD";

    vector<string> res(n, string(m, '.'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (char c : letters) {
                if (c == grid[i][j]) continue;
                
                if (i > 0 && res[i - 1][j] == c) continue;
                if (j > 0 && res[i][j - 1] == c) continue;

                res[i][j] = c;
                break;
            }
        }
    }

    for (const string& row : res) {
        cout << row << "\n";
    }

    return 0;
}
