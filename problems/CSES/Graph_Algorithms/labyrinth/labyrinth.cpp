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

    pair<int, int> start;
    pair<int, int> end;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 'A') {
                start = {r, c};
            } else if (grid[r][c] == 'B') {
                end = {r, c};
            }
        }
    }

    vector<tuple<int, int, char>> directions = {
        {-1, 0, 'U'},
        {1, 0, 'D'},
        {0, -1, 'L'},
        {0, 1, 'R'}
    };

    queue<pair<int, int>> q;
    q.push(start);

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[start.first][start.second] = true;

    vector<vector<char>> parent(n, vector<char>(m));

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (make_pair(r, c) == end) {
            break;
        }

        for (auto [dr, dc, move] : directions) {
            int nr = r + dr;
            int nc = c + dc;

            if (
                0 <= nr && nr < n &&
                0 <= nc && nc < m &&
                grid[nr][nc] != '#' &&
                !visited[nr][nc]
            ) {
                visited[nr][nc] = true;
                parent[nr][nc] = move;
                q.push({nr, nc});
            }
        }
    }

    if (!visited[end.first][end.second]) {
        cout << "NO\n";
        return 0;
    }

    string path;

    int r = end.first;
    int c = end.second;

    while (make_pair(r, c) != start) {
        char move = parent[r][c];

        path.push_back(move);

        if (move == 'U') {
            r++;
        } else if (move == 'D') {
            r--;
        } else if (move == 'L') {
            c++;
        } else if (move == 'R') {
            c--;
        }
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path << '\n';

    return 0;
}
