#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

const int N = 8;

vector<pair<int, int>> moves = {
    {2, 1}, {2, -1},
    {-2, 1}, {-2, -1},
    {1, 2}, {1, -2},
    {-1, 2}, {-1, -2}
};

int board[N][N];

int degree(int r, int c) {
    int count = 0;

    for (auto [dr, dc] : moves) {
        int nr = r + dr;
        int nc = c + dc;

        if (0 <= nr && nr < N &&
            0 <= nc && nc < N &&
            board[nr][nc] == 0) {
            count++;
        }
    }

    return count;
}

bool dfs(int r, int c, int step) {
    board[r][c] = step;

    if (step == 64) return true;

    vector<tuple<int, int, int>> nextMoves;

    for (auto [dr, dc] : moves) {
        int nr = r + dr;
        int nc = c + dc;

        if (0 <= nr && nr < N &&
            0 <= nc && nc < N &&
            board[nr][nc] == 0) {

            nextMoves.push_back({
                degree(nr, nc),
                nr,
                nc
            });
        }
    }

    sort(nextMoves.begin(), nextMoves.end());

    for (auto [deg, nr, nc] : nextMoves) {
        if (dfs(nr, nc, step + 1))
            return true;
    }

    board[r][c] = 0;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    x--;
    y--;

    dfs(y, x, 1);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << board[r][c];
            if (c + 1 < N) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
