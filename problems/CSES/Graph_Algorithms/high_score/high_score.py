import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    edges = []
    reverse_graph = [[] for _ in range(n)]

    for _ in range(m):
        a, b, x = map(int, input().split())
        a -= 1
        b -= 1

        edges.append((a, b, x))
        reverse_graph[b].append(a)

    can_reach_n = [False] * n
    queue = deque([n - 1])
    can_reach_n[n - 1] = True

    while queue:
        u = queue.popleft()

        for v in reverse_graph[u]:
            if not can_reach_n[v]:
                can_reach_n[v] = True
                queue.append(v)

    NEG_INF = -10 ** 30

    dist = [NEG_INF] * n
    dist[0] = 0

    # Bellman-Ford
    for _ in range(n - 1):
        changed = False

        for u, v, w in edges:
            if dist[u] == NEG_INF:
                continue

            if dist[u] + w > dist[v]:
                dist[v] = dist[u] + w
                changed = True

        if not changed:
            break

    for u, v, w in edges:
        if dist[u] == NEG_INF:
            continue

        if dist[u] + w > dist[v]:
            if can_reach_n[v]:
                print(-1)
                return

    print(dist[n - 1])

main()
