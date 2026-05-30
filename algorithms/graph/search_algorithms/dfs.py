# use sys.setrecursionlimit(10**7) when you use recursive version

# Depth First Search Algorithm:
# Time Complexity:
# O( V + E ), где:
# V — количество вершин,
# E — количество рёбер.
#
# Space Complexity:
# Memory: O( V )

def dfs_recursive(graph, start, visited):
    visited[start] = True

    for nei in graph[start]:
        if not visited[nei]:
            dfs_recursive(nei, graph, visited)

def dfs_iterative(graph, start):
    visited = [False] * len(graph)
    stack = [start]

    while stack:
        curr = stack.pop()

        if visited[curr]:
            continue

        visited[curr] = True

        for nei in graph[curr]:
            if not visited[nei]:
                stack.append(nei)

    return visited

# Examples to use:
# n, m = map(int, input().split())
# graph = [[] for _ in range(n)]
#
# for _ in range(m):
#     a, b = map(int, input().split())
#     graph[a].append(b)
#     graph[b].append(a)  # not oriented graph
#
# visited = [False] * n
# dfs_recursive(0, graph, visited)

# Intuition / Idea (backtracking):
# “исследуй один путь полностью, прежде чем переключиться на другой”
# “Я пойду максимально глубоко по одному пути, пока не упрёмся в тупик. Потом вернусь назад и попробую другой путь.”

# Where to use:
# 1. Проверка связности - Можно ли добраться из A в B?
# 2. Компоненты связности - Сколько “островов” в графе?
# 3. Поиск циклов
# 4. Топологическая сортировка (DAG)
# 5. Backtracking (перебор)
# 6. Labyrinth
# 7. Tree
# 8. Проверка двудольности
