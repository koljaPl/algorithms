import sys
import heapq
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    MOD = 10 ** 9 + 7
    INF = 10 ** 30

    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]

    for _ in range(m):
        a, b, c = map(int, input().split())
        graph[a - 1].append((b - 1, c))

    dist = [INF] * n
    ways = [0] * n
    min_flights = [10 ** 9] * n
    max_flights = [0] * n

    dist[0] = 0
    ways[0] = 1
    min_flights[0] = 0
    max_flights[0] = 0

    pq = [(0, 0)]  # (distance, vertex)

    while pq:
        cur_dist, v = heapq.heappop(pq)

        if cur_dist != dist[v]:
            continue

        for u, w in graph[v]:
            new_dist = cur_dist + w

            if new_dist < dist[u]:
                dist[u] = new_dist

                ways[u] = ways[v]
                min_flights[u] = min_flights[v] + 1
                max_flights[u] = max_flights[v] + 1

                heapq.heappush(pq, (new_dist, u))

            elif new_dist == dist[u]:
                ways[u] = (ways[u] + ways[v]) % MOD

                min_flights[u] = min(min_flights[u], min_flights[v] + 1)
                max_flights[u] = max(max_flights[u], max_flights[v] + 1)

    print(
        dist[n - 1],
        ways[n - 1],
        min_flights[n - 1],
        max_flights[n - 1]
    )

main()
