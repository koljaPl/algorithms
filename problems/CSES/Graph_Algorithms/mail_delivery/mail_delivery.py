import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]
    degree = [0] * n

    for edge_id in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        graph[a].append((b, edge_id))
        graph[b].append((a, edge_id))

        degree[a] += 1
        degree[b] += 1

    for v in range(n):
        if degree[v] % 2:
            print("IMPOSSIBLE")
            return

    used = [False] * m
    index = [0] * n

    stack = [0]
    path = []

    while stack:
        v = stack[-1]

        while index[v] < len(graph[v]) and used[graph[v][index[v]][1]]:
            index[v] += 1

        if index[v] == len(graph[v]):
            path.append(v)
            stack.pop()

        else:
            u, edge_id = graph[v][index[v]]
            index[v] += 1

            if not used[edge_id]:
                used[edge_id] = True
                stack.append(u)

    if len(path) != m + 1:
        print("IMPOSSIBLE")
        return

    path.reverse()

    print(*[v + 1 for v in path])

main()