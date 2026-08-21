import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    edges = []

    for _ in range(m):
        u, v, w = map(int, input().split()) # From / To / Cost

        u -= 1
        v -= 1

        edges.append((u, v, w))

    # Bellman-Ford
    dist = [0] * n
    parent = [-1] * n

    x = -1

    for _ in range(n):
        x = -1

        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                parent[v] = u
                x = v

    if x == -1:
        print("NO")
        return

    for _ in range(n):
        x = parent[x]

    cycle = [x]
    cur = parent[x]

    while cur != x:
        cycle.append(cur)
        cur = parent[cur]

    cycle.append(x)

    cycle.reverse()

    print("YES")
    print(*(v + 1 for v in cycle))

main()
