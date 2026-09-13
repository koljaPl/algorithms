#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n, k;
vector<string> target;
vector<vector<string>> pieces;

bool valid_shift(const vector<string>& p, int dr, int dc) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (p[r][c] == '#') {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) return false;
            }
        }
    }
    return true;
}

bool match(int i, int dr1, int dc1, int j, int dr2, int dc2) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            bool has1 = false, has2 = false;

            int orig_r1 = r - dr1, orig_c1 = c - dc1;
            if (orig_r1 >= 0 && orig_r1 < n && orig_c1 >= 0 && orig_c1 < n) {
                if (pieces[i][orig_r1][orig_c1] == '#') has1 = true;
            }

            int orig_r2 = r - dr2, orig_c2 = c - dc2;
            if (orig_r2 >= 0 && orig_r2 < n && orig_c2 >= 0 && orig_c2 < n) {
                if (pieces[j][orig_r2][orig_c2] == '#') has2 = true;
            }

            if (has1 && has2) return false;

            bool target_has = (target[r][c] == '#');
            if ((has1 || has2) != target_has) return false;
        }
    }
    return true;
}

int main() {
    setIO("bcs");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    target.resize(n);
    for (int i = 0; i < n; i++) cin >> target[i];

    pieces.assign(k, vector<string>(n));
    for (int i = 0; i < k; i++) {
        for (int r = 0; r < n; r++) {
            cin >> pieces[i][r];
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            for (int dr1 = -n + 1; dr1 < n; dr1++) {
                for (int dc1 = -n + 1; dc1 < n; dc1++) {
                    if (!valid_shift(pieces[i], dr1, dc1)) continue;

                    for (int dr2 = -n + 1; dr2 < n; dr2++) {
                        for (int dc2 = -n + 1; dc2 < n; dc2++) {
                            if (!valid_shift(pieces[j], dr2, dc2)) continue;

                            if (match(i, dr1, dc1, j, dr2, dc2)) {
                                cout << i + 1 << " " << j + 1 << "\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
