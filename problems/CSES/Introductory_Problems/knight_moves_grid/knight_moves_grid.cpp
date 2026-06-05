#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> moves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[0][0] = 0;

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto& move : moves) {
            int nr = r + move[0];
            int nc = c + move[1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }

    for (const auto& row : dist) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }

    return 0;
}
