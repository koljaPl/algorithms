#include <bits/stdc++.h>
using namespace std;

// Depth First Search Algorithm:
// Time Complexity:
// O( V + E ), где:
// V — количество вершин,
// E — количество рёбер.
//
// Space Complexity:
// Memory: O( V )

void dfs_recursive(
    const vector<vector<int>>& graph,
    int start,
    vector<bool>& visited
) {
    visited[start] = true;

    for (int nei : graph[start]) {
        if (!visited[nei]) {
            dfs_recursive(graph, nei, visited);
        }
    }
}

vector<bool> dfs_iterative(
    const vector<vector<int>>& graph,
    int start
) {
    vector<bool> visited(graph.size(), false);

    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int curr = st.top();
        st.pop();

        if (visited[curr]) {
            continue;
        }

        visited[curr] = true;

        for (int nei : graph[curr]) {
            if (!visited[nei]) {
                st.push(nei);
            }
        }
    }

    return visited;
}

// Examples to use:
// int n, m;
// cin >> n >> m;
//
// vector<vector<int>> graph(n);
//
// for (int i = 0; i < m; i++) {
//     int a, b;
//     cin >> a >> b;
//
//     graph[a].push_back(b);
//     graph[b].push_back(a);  // not oriented graph
// }
//
// vector<bool> visited(n, false);
// dfs_recursive(graph, 0, visited);

// Intuition / Idea (backtracking):
// "исследуй один путь полностью, прежде чем переключиться на другой"
// "Я пойду максимально глубоко по одному пути, пока не упрёмся в тупик. Потом вернусь назад и попробую другой путь."

// Where to use:
// 1. Проверка связности - Можно ли добраться из A в B?
// 2. Компоненты связности - Сколько "островов" в графе?
// 3. Поиск циклов
// 4. Топологическая сортировка (DAG)
// 5. Backtracking (перебор)
// 6. Labyrinth
// 7. Tree
// 8. Проверка двудольности