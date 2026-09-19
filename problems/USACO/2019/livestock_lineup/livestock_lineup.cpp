#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("lineup");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<string, string>> constraints;
    for (int i = 0; i < n; ++i) {
        string cow1, cow2, trash;

        cin >> cow1;
        cin >> trash >> trash >> trash >> trash;
        cin >> cow2;

        constraints.pb({cow1, cow2});
    }

    vector<string> cows = {
        "Beatrice", "Belinda", "Bella", "Bessie",
        "Betsy", "Blue", "Buttercup", "Sue"
    };
    sort(cows.begin(), cows.end());

    do {
        bool ok = true;
        for (const auto& p : constraints) {
            int pos1 = -1, pos2 = -1;

            for (int i = 0; i < 8; ++i) {
                if (cows[i] == p.first) pos1 = i;
                if (cows[i] == p.second) pos2 = i;
            }

            if (abs(pos1 - pos2) != 1) {
                ok = false;
                break;
            }
        }

        if (ok) {
            for (const string& cow : cows) {
                cout << cow << "\n";
            }
            break;
        }
    } while (next_permutation(cows.begin(), cows.end()));

    return 0;
}
