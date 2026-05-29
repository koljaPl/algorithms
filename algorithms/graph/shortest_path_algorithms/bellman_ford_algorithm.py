# Bellman Ford Algorithm
# Time Complexity:
# O( V * E ), где:
# V — количество вершин,
# E — количество рёбер.
#
# Space Complexity:
# Memory: O(V)

def bellman_ford(n, edges, start):
    INF = float('inf')

    dist = [INF] * n
    dist[start] = 0

    for _ in range(n - 1):
        updated = False

        for u, v, w in edges:
            if dist[u] == INF:
                continue

            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                updated = True

        if not updated:
            break

    has_negative_cycle = False

    for u, v, w in edges:
        if dist[u] == INF:
            continue

        if dist[u] + w < dist[v]:
            has_negative_cycle = True
            break

    return dist, has_negative_cycle

# Bellman–Ford это то же самое что и Dijkstra но чуть медленее и может работать с
# отрицательными рёбрами и может обнаруживать отрицательные циклы

# Bellman–Ford — это “динамическое программирование по количеству рёбер”
# Bellman–Ford не “строит путь”, а постепенно улучшает оценки расстояний.
# dp[k][v]
# =
# минимальная стоимость добраться до v
# используя максимум k рёбер

# Where to use:
# Problems like:
# 1. Negative Cycle Detection
# 2. High Score (CSES)
# 3. Currency Arbitrage
# 4. Difference Constraints
