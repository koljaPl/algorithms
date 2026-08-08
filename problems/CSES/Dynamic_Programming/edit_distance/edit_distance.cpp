#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int n = static_cast<int>(a.size());
    int m = static_cast<int>(b.size());

    vector<int> previous(m + 1);
    vector<int> current(m + 1);

    for (int j = 0; j <= m; ++j) {
        previous[j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        current[0] = i;

        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                current[j] = previous[j - 1];
            } else {
                int removeChar = previous[j];
                int addChar = current[j - 1];
                int replaceChar = previous[j - 1];

                current[j] = 1 + min({
                    removeChar,
                    addChar,
                    replaceChar
                });
            }
        }

        swap(previous, current);
    }

    cout << previous[m] << '\n';

    return 0;
}
