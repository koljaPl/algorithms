from collections import deque

# Breadth First Search algorithm:
# Time Complexity:
# O(V+E), где:
# V — количество вершин,
# E — количество рёбер.
#
# Space Complexity:
# Memory: O(V)

def bfs_on_graph(graph, start):
    n = len(graph)
    visited = [False] * n
    distances = [-1] * n

    queue = deque()
    queue.append(start)
    visited[start] = True
    distances[start] = 0

    while queue:
        node = queue.popleft()

        for nei in graph[node]:
            if not visited[nei]:
                visited[nei] = True
                distances[nei] = distances[node] + 1
                queue.append(nei)

    return distances

def bfs_on_grid(grid, start_x, start_y):
    m, n = len(grid), len(grid[0])
    distances = [[-1] * m for _ in range(n)]

    queue = deque()
    queue.append((start_x, start_y))
    distances[start_x][start_y] = 0

    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    while queue:
        x, y = queue.popleft()

        for dx, dy in directions:
            new_x, new_y = x + dx, y + dy

            if 0 <= new_x < n and 0 <= new_y < m:
                if grid[new_x][new_y] != "#" and distances[new_x][new_y] == -1:
                    distances[new_x][new_y] = distances[x][y] + 1
                    queue.append((new_x, new_y))

    return distances

# Where to use:
# Если ты видишь:
#
# “минимальное число шагов”
# “за сколько ходов”
# “распространение”
# “grid”
# “каждый шаг = 1 стоимость”


