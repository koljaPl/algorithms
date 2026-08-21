#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> representatives;
    vector<int> stack;

    for (int city = 1; city <= n; ++city) {
        if (!visited[city]) {
            representatives.push_back(city);
            
            stack.push_back(city);
            visited[city] = true;

            while (!stack.empty()) {
                int node = stack.back();
                stack.pop_back();

                for (int nei : graph[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        stack.push_back(nei);
                    }
                }
            }
        }
    }

    cout << representatives.size() - 1 << "\n";

    for (size_t i = 1; i < representatives.size(); ++i) {
        cout << representatives[i - 1] << " " << representatives[i] << "\n";
    }

    return 0;
}
