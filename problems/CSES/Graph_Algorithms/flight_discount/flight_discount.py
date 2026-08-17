import sys
import heapq
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def dijkstra_ioi(n, adj, start):
    INF = 10 ** 18 + 1

    dist = [INF] * (n + 1)
    dist[start] = 0

    priority_queue = [(0, start)]

    while priority_queue:
        cur_dist, u = heapq.heappop(priority_queue)

        if cur_dist != dist[u]:
            continue

        for v, w in adj[u]:
            new_dist = cur_dist + w

            if new_dist < dist[v]:
                dist[v] = new_dist
                heapq.heappush(priority_queue, (new_dist, v))

    return dist

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n + 1)]
    reverse_graph = [[] for _ in range(n + 1)]

    edges = []

    for _ in range(m):
        a, b, c = map(int, input().split())

        graph[a].append((b, c))
        reverse_graph[b].append((a, c))

        edges.append((a, b, c))

    dist1 = dijkstra_ioi(n, graph, 1)
    distN = dijkstra_ioi(n, reverse_graph, n)

    res = float("inf")

    for a, b, c in edges:
        cost = dist1[a] + c // 2 + distN[b]
        res = min(res, cost)

    print(res)

main()
