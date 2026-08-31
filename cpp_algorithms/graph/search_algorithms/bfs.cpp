#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

// Breadth First Search Algorithm:
//
// Time Complexity:
// O(V + E), где:
// V — количество вершин,
// E — количество рёбер.
//
// Space Complexity:
// Memory: O(V)

vector<int> bfs_on_graph(const vector<vector<int>>& graph, int start) {
    int n = graph.size();

    vector<bool> visited(n, false);
    vector<int> distances(n, -1);

    queue<int> q;

    q.push(start);
    visited[start] = true;
    distances[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int nei : graph[node]) {
            if (!visited[nei]) {
                visited[nei] = true;
                distances[nei] = distances[node] + 1;

                q.push(nei);
            }
        }
    }

    return distances;
}


// BFS on Grid:
//
// Time Complexity:
// O(n * m)
//
// Space Complexity:
// O(n * m)

vector<vector<int>> bfs_on_grid(
    const vector<string>& grid,
    int start_x,
    int start_y
) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> distances(
        n,
        vector<int>(m, -1)
    );

    queue<pair<int, int>> q;

    q.push({start_x, start_y});
    distances[start_x][start_y] = 0;

    vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int new_x = x + dx;
            int new_y = y + dy;

            if (
                new_x >= 0 && new_x < n &&
                new_y >= 0 && new_y < m
            ) {
                if (
                    grid[new_x][new_y] != '#' &&
                    distances[new_x][new_y] == -1
                ) {
                    distances[new_x][new_y] =
                        distances[x][y] + 1;

                    q.push({new_x, new_y});
                }
            }
        }
    }

    return distances;
}

// Where to use:
//
// Если ты видишь:
//
// "минимальное число шагов"
// "за сколько ходов"
// "распространение"
// "grid"
// "каждый шаг = 1 стоимость"
