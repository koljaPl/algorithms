#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("buckets");

    vector<vector<char>> grid(10, vector<char>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
        }
    }

    int sr, sc, br, bc;
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            if (grid[r][c] == 'L') {
                sr = r;
                sc = c;
            } else if (grid[r][c] == 'B') {
                br = r;
                bc = c;
            }
        }
    }

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> dist(10, vector<int>(10, -1));
    dist[sr][sc] = 0;

    deque<pair<int, int>> q;
    q.push_back({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop_front();

        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;

        if (!(0 <= nr && nr < 10 && 0 <= nc && nc < 10)) {
            continue;
        }

        if (dist[nr][nc] != -1) {
            continue;
        }

        if (grid[nr][nc] == 'R') {
            continue;
        }

        dist[nr][nc] = dist[r][c] + 1;
        q.push_back({nr, nc});
        }
    }

    cout << dist[br][bc] - 1 << endl;

    return 0;
}
