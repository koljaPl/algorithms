#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
bool visited[9][9];
int res = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int steps) {
    if (r == 7 && c == 1) {
        if (steps == 48) res++;
        return;
    }
    
    if (steps == 48) return;

    if (visited[r-1][c] && visited[r+1][c] && !visited[r][c-1] && !visited[r][c+1]) return;
    if (visited[r][c-1] && visited[r][c+1] && !visited[r-1][c] && !visited[r+1][c]) return;

    visited[r][c] = true;

    if (s[steps] != '?') {
        int dir_idx = -1;
        if (s[steps] == 'U') dir_idx = 0;
        else if (s[steps] == 'D') dir_idx = 1;
        else if (s[steps] == 'L') dir_idx = 2;
        else if (s[steps] == 'R') dir_idx = 3;

        int next_r = r + dr[dir_idx];
        int next_c = c + dc[dir_idx];
        if (!visited[next_r][next_c]) {
            dfs(next_r, next_c, steps + 1);
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            if (!visited[next_r][next_c]) {
                dfs(next_r, next_c, steps + 1);
            }
        }
    }

    visited[r][c] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    for (int i = 0; i < 9; i++) {
        visited[0][i] = visited[8][i] = true;
        visited[i][0] = visited[i][8] = true;
    }

    dfs(1, 1, 0);

    cout << res << "\n";

    return 0;
}
