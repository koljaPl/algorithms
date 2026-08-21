import sys
import heapq
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]
    for _ in range(m):
        a, b, c = map(int, input().split())

        a -= 1
        b -= 1

        graph[a].append((b, c))

    INF = float('inf')

    dist = [INF] * n
    parent = [-1] * n

    dist[0] = 0

    # Min-Heap / Priority Queue
    priority_queue = [(0, 0)]

    while priority_queue:
        cur_dist, u = heapq.heappop(priority_queue)

        if cur_dist > dist[u]:
            continue

        for v, w in graph[u]:
            new_dist = cur_dist + w

            if new_dist < dist[v]:
                dist[v] = new_dist
                parent[v] = u
                heapq.heappush(priority_queue, (new_dist, v))

    print(*dist)

main()
