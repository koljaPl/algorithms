#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    vector<bool> cols(8, false);
    vector<bool> diag1(15, false);
    vector<bool> diag2(15, false);

    int res = 0;

    auto dfs = [&](auto& self, int row) -> void {
        if (row == 8) {
            res++;
            return;
        }
        for (int col = 0; col < 8; col++) {
            if (board[row][col] == '*') continue;

            int d1 = row - col + 7;
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            self(self, row + 1);

            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    };

    dfs(dfs, 0);

    cout << res << "\n";

    return 0;
}
