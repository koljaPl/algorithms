#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (string& row : grid) {
        cin >> row;
    }

    vector<int> frontier = {0};
    string res(1, grid[0][0]);

    vector<int> seen(n, 0);
    int stamp = 0;

    for (int diagonal = 1; diagonal < 2 * n - 1; ++diagonal) {
        ++stamp;

        vector<int> candidates;
        char bestChar = '{';

        for (int row : frontier) {
            int previousCol = diagonal - 1 - row;

            if (previousCol + 1 < n && seen[row] != stamp) {
                seen[row] = stamp;
                candidates.push_back(row);

                int col = diagonal - row;
                bestChar = min(bestChar, grid[row][col]);
            }

            int nextRow = row + 1;

            if (nextRow < n && seen[nextRow] != stamp) {
                seen[nextRow] = stamp;
                candidates.push_back(nextRow);

                int col = diagonal - nextRow;
                bestChar = min(bestChar, grid[nextRow][col]);
            }
        }

        frontier.clear();

        for (int row : candidates) {
            int col = diagonal - row;

            if (grid[row][col] == bestChar) {
                frontier.push_back(row);
            }
        }

        res.push_back(bestChar);
    }

    cout << res << '\n';

    return 0;
}
