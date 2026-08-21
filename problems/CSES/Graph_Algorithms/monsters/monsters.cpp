#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};
const char moves_dir[4] = {'D', 'U', 'R', 'L'};

struct Step {
    int r, c;
    char move;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vector<vector<int>> monster_dist(n, vector<int>(m, INF));
    vector<vector<int>> player_dist(n, vector<int>(m, -1));
    vector<vector<Step>> parent(n, vector<Step>(m));

    queue<pair<int, int>> q;
    pair<int, int> start = {-1, -1};

    for (int r = 0; r < n; ++r) {
        cin >> grid[r];
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == 'M') {
                monster_dist[r][c] = 0;
                q.push({r, c});
            } else if (grid[r][c] == 'A') {
                start = {r, c};
            }
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                grid[nr][nc] != '#' && monster_dist[nr][nc] == INF) {
                monster_dist[nr][nc] = monster_dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    auto [sr, sc] = start;

    if (sr == 0 || sr == n - 1 || sc == 0 || sc == m - 1) {
        cout << "YES\n0\n\n";
        return 0;
    }

    queue<pair<int, int>> player_q;
    player_q.push({sr, sc});
    player_dist[sr][sc] = 0;

    pair<int, int> end_node = {-1, -1};

    while (!player_q.empty()) {
        auto [r, c] = player_q.front();
        player_q.pop();

        bool reached_exit = false;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#') continue;
            if (player_dist[nr][nc] != -1) continue;

            int new_dist = player_dist[r][c] + 1;
            if (new_dist >= monster_dist[nr][nc]) continue;

            player_dist[nr][nc] = new_dist;
            parent[nr][nc] = {r, c, moves_dir[i]};

            if (nr == 0 || nr == n - 1 || nc == 0 || nc == m - 1) {
                end_node = {nr, nc};
                reached_exit = true;
                break;
            }

            player_q.push({nr, nc});
        }

        if (reached_exit) break;
    }

    if (end_node.first == -1) {
        cout << "NO\n";
    } else {
        string path = "";
        int r = end_node.first;
        int c = end_node.second;

        while (r != sr || c != sc) {
            Step p = parent[r][c];
            path += p.move;
            r = p.r;
            c = p.c;
        }

        reverse(path.begin(), path.end());

        cout << "YES\n" << path.size() << "\n" << path << "\n";
    }

    return 0;
}
