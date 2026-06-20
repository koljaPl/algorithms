#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int res = 0, last_end = 0;
    for (const auto& movie : movies) {
        if (movie.first >= last_end) {
            res++;
            last_end = movie.second;
        }
    }

    cout << res << "\n";

    return 0;
}
