#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int rooms = 0;

    vector<pair<int, int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] != '.')
                continue;

            rooms++;

            deque<pair<int, int>> q;
            q.push_back({r, c});
            grid[r][c] = '#';

            while (!q.empty()) {
                auto [row, col] = q.front();
                q.pop_front();

                for (auto [dr, dc] : directions) {
                    int nr = row + dr;
                    int nc = col + dc;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.') {
                        grid[nr][nc] = '#';
                        q.push_back({nr, nc});
                    }
                }
            }
        }
    }

    cout << rooms << '\n';

    return 0;
}
