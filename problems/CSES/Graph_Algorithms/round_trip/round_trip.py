import sys
sys.setrecursionlimit(300000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    visited = [False] * (n + 1)
    parent = [-1] * (n + 1)

    cycle_start = -1
    cycle_end = -1

    def dfs(u, p):
        nonlocal cycle_start, cycle_end

        visited[u] = True

        for v in graph[u]:
            if v == p:
                continue

            if visited[v]:
                cycle_start = v
                cycle_end = u
                return True

            parent[v] = u

            if dfs(v, u):
                return True

        return False

    for i in range(1, n + 1):
        if not visited[i]:
            if dfs(i, -1):
                break

    if cycle_start == -1:
        print("IMPOSSIBLE")
        return

    cycle = [cycle_start]

    cur = cycle_end

    while cur != cycle_start:
        cycle.append(cur)
        cur = parent[cur]

    cycle.append(cycle_start)

    print(len(cycle))
    print(*cycle)

main()
