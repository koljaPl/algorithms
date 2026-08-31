import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]
    rev = [[] for _ in range(n)]

    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        graph[a].append(b)
        rev[b].append(a)

    visited = [False] * n
    order = []

    for start in range(n):
        if visited[start]:
            continue

        stack = [(start, 0)]

        while stack:
            v, state = stack.pop()

            if state == 1:
                order.append(v)
                continue

            if visited[v]:
                continue

            visited[v] = True
            stack.append((v, 1))

            for u in graph[v]:
                if not visited[u]:
                    stack.append((u, 0))

    kingdom = [0] * n
    k = 0

    for start in reversed(order):
        if kingdom[start] != 0:
            continue

        k += 1
        stack = [start]
        kingdom[start] = k

        while stack:
            v = stack.pop()

            for u in rev[v]:
                if kingdom[u] == 0:
                    kingdom[u] = k
                    stack.append(u)

    print(k)
    print(*kingdom)

main()
