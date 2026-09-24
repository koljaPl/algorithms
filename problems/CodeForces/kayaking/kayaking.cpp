#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void solve() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int total_people = 2 * n;
    vector<int> w(total_people);
    for (int i = 0; i < total_people; i++) cin >> w[i];

    sort(w.begin(), w.end());

    int min_instability = INT_MAX;

    for (int i = 0; i < total_people; i++) {
        for (int j = i + 1; j < total_people; j++) {
            
            vector<int> remaining;
            for (int k = 0; k < total_people; k++) {
                if (k != i && k != j) {
                    remaining.push_back(w[k]);
                }
            }

            int current_instability = 0;
            for (size_t k = 0; k < remaining.size(); k += 2) {
                current_instability += remaining[k + 1] - remaining[k];
            }

            min_instability = min(min_instability, current_instability);
        }
    }

    cout << min_instability << "\n";

    return 0;
}
