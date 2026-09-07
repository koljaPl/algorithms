import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]
    indegree = [0] * n
    outdegree = [0] * n

    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        graph[a].append(b)
        outdegree[a] += 1
        indegree[b] += 1

    if outdegree[0] != indegree[0] + 1:
        print("IMPOSSIBLE")
        return

    if indegree[n - 1] != outdegree[n - 1] + 1:
        print("IMPOSSIBLE")
        return

    for v in range(1, n - 1):
        if indegree[v] != outdegree[v]:
            print("IMPOSSIBLE")
            return

    stack = [0]
    path = []

    while stack:
        v = stack[-1]

        if graph[v]:
            u = graph[v].pop()
            stack.append(u)
        else:
            path.append(stack.pop())

    path.reverse()

    if len(path) != m + 1:
        print("IMPOSSIBLE")
        return

    if path[0] != 0 or path[-1] != n - 1:
        print("IMPOSSIBLE")
        return

    print(*(v + 1 for v in path))

main()
