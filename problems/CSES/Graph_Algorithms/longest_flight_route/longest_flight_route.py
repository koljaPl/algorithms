import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    adj = [[] for _ in range(n + 1)]
    in_degree = [0] * (n + 1)

    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        in_degree[v] += 1

    q = deque([i for i in range(1, n + 1) if in_degree[i] == 0])

    INF = 10 ** 9
    dist = [-INF] * (n + 1)
    parent = [0] * (n + 1)

    dist[1] = 1

    while q:
        u = q.popleft()

        for v in adj[u]:
            if dist[u] != -INF and dist[u] + 1 > dist[v]:
                dist[v] = dist[u] + 1
                parent[v] = u

            in_degree[v] -= 1
            if in_degree[v] == 0:
                q.append(v)

    if dist[n] < 0:
        print("IMPOSSIBLE")
    else:
        print(dist[n])
        path = []
        curr = n
        while curr != 0:
            path.append(curr)
            curr = parent[curr]

        path.reverse()
        print(*path)

main()
