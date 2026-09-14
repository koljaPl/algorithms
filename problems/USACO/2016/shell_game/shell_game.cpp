#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct Move {
    int a, b, g;
};

int main() {
    setIO("shell");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Move> moves(n);
    for (int i = 0; i < n; i++) {
        cin >> moves[i].a >> moves[i].b >> moves[i].g;
    }

    int res = 0;

    for (int start_pos = 1; start_pos <= 3; start_pos++) {
        int curr_pos = start_pos;
        int score = 0;

        for (const auto& m : moves) {
            if (curr_pos == m.a) {
                curr_pos = m.b;
            } else if (curr_pos == m.b) {
                curr_pos = m.a;
            }

            if (curr_pos == m.g) {
                score++;
            }
        }

        res = max(res, score);
    }

    cout << res << "\n";

    return 0;
}
