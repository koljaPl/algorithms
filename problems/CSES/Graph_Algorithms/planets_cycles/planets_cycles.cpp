#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

int main() {
    int n;
    cin >> n;

    vector<int> to(n);

    for (int i = 0; i < n; i++) {
        cin >> to[i];
        to[i]--;
    }

    vector<int> state(n, 0);
    vector<int> res(n, 0);

    for (int start = 0; start < n; start++) {
        if (state[start] != 0) {
            continue;
        }

        vector<int> path;

        int v = start;

        while (state[v] == 0) {
            state[v] = 1;

            path.push_back(v);

            v = to[v];
        }

        if (state[v] == 1) {

            int cycle_start = 0;

            while (path[cycle_start] != v) {
                cycle_start++;
            }

            int cycle_length = path.size() - cycle_start;

            for (int i = cycle_start; i < path.size(); i++) {
                res[path[i]] = cycle_length;
            }

            for (int i = cycle_start - 1; i >= 0; i--) {

                int node = path[i];

                res[node] = res[to[node]] + 1;
            }
        }
        else {
            for (int i = path.size() - 1; i >= 0; i--) {

                int node = path[i];

                res[node] = res[to[node]] + 1;
            }
        }

        for (int node : path) {
            state[node] = 2;
        }
    }

    for (int x : res) {
        cout << x << " ";
    }

    cout << '\n';
}
