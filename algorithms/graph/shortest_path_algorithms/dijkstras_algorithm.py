import heapq

# Dijkstra's Algorithm
# Time Complexity:
# O( ( V + E ) log V ), где:
# V — количество вершин,
# E — количество рёбер.
#
# Space Complexity:
# Memory: O( V + E )

def dijkstra(n, adj, start):
    INF = float('inf')

    dist = [INF] * n
    dist[start] = 0

    # Min-Heap / Priority Queue
    priority_queue = [(0, start)]  # (distance, node)

    while priority_queue:
        cur_dist, u = heapq.heappop(priority_queue)

        # outdated entry
        if cur_dist > dist[u]:
            continue

        for v, w in adj[u]:
            new_dist = cur_dist + w

            if new_dist < dist[v]:
                dist[v] = new_dist
                heapq.heappush(priority_queue, (new_dist, v))

    return dist

# Goal: Найти кратчайшие расстояния от одной вершины до всех остальных в графе с неотрицательными весами рёбер.

# Where to use:
# shortest path
# cheapest route
# minimum cost
# navigation
# weighted graph
# flight routes
# network delay
# road systems

# Как собрать с adjacency list?
#
# Undirected graph:
# n, m = map(int, input().split())
#
# adj = [[] for _ in range(n)]
#
# for _ in range(m):
#     u, v, w = map(int, input().split()) # From / To / Cost
#
#     u -= 1
#     v -= 1
#
#     adj[u].append((v, w))
#     adj[v].append((u, w))
#
# Directed graph:
# n, m = map(int, input().split())
#
# adj = [[] for _ in range(n)]
#
# for _ in range(m):
#     u, v, w = map(int, input().split()) # From / To / Cost
#
#     u -= 1
#     v -= 1
#
#     adj[u].append((v, w))

def dijkstra_with_path(n, adj, start):
    INF = float('inf')

    dist = [INF] * n
    parent = [-1] * n

    dist[start] = 0

    # Min-Heap / Priority Queue
    priority_queue = [(0, start)]

    while priority_queue:
        cur_dist, u = heapq.heappop(priority_queue)

        if cur_dist > dist[u]:
            continue

        for v, w in adj[u]:
            new_dist = cur_dist + w

            if new_dist < dist[v]:
                dist[v] = new_dist
                parent[v] = u
                heapq.heappush(priority_queue, (new_dist, v))

    return dist, parent

# Or more IOI version of Dijkstra:
def dijkstra_ioi(n, adj, start):
    INF = 10 ** 18 + 1

    dist = [INF] * n
    dist[start] = 0

    # Min-Heap / Priority Queue
    priority_queue = [(0, start)]

    while priority_queue:
        cur_dist, u = heapq.heappop(priority_queue)

        # Это то же самое что и > потому что мы используем Heap,
        # а у Heap есть особенность делать только меньшее число наверх
        # тоесть: разрешаем только единственную актуальную версию
        # что значит что мы утверждаем что точно есть 1 правильный путь
        if cur_dist != dist[u]:
            continue

        for v, w in adj[u]:
            new_dist = cur_dist + w

            if new_dist < dist[v]:
                dist[v] = new_dist
                heapq.heappush(priority_queue, (new_dist, v))

    return dist
