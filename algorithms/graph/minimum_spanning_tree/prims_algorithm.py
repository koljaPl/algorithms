import heapq

# Prim's algorithm:
# Time Complexity:
# O( (V + E) log V ), где:
# V — количество вершин,
# E — количество рёбер.
#
# Space Complexity:
# Memory: O( V + E )

def prims_algorithm(n, graph):
    visited = [False] * n
    min_heap = []

    # mst - Minimum Spanning Tree
    mst_weight = 0

    visited[0] = True

    for to, w in graph[0]:
        heapq.heappush(min_heap, (w, to))

    edges_used = 0

    while min_heap and edges_used < n - 1:
        w, v = heapq.heappop(min_heap)

        if visited[v]:
            continue

        visited[v] = True
        mst_weight += w
        edges_used += 1

        for to, cost in graph[v]:
            if not visited[to]:
                heapq.heappush(min_heap, (cost, to))

    if edges_used != n - 1:
        return None

    return mst_weight


# Алгоритм Прима:
# "растим дерево, каждый раз добавляя самое дешёвое ребро, которое подключает новую вершину"

# на каждом шаге выбирает ребро минимального веса, которое соединяет:
# вершину, уже находящуюся в построенном дереве,
# с вершиной, которая ещё не подключена.

# То есть:
#
# 1. Берём любую стартовую вершину.
# 2. Смотрим все рёбра, выходящие из уже подключённых вершин.
# 3. Выбираем самое дешёвое ребро, ведущее наружу.
# 4. Добавляем новую вершину и ребро.
# 5. Повторяем, пока не подключим все вершины.

# У нас есть возможность выберать самое дешевое ребро изза особености Heap оставлять
# лучшею для нас возможность выбрать самое дешевое.

# When to use:
# Когда граф плотный

# Where to use:
# 1. Классическая задача MST
# 2. Геометрические MST-задачи
# 3. connect all points with minimum cost
# 4. minimum cable length
# 5. minimum wiring cost
# 6. build a network with minimum expense
