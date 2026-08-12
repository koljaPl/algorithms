import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    queue = deque([1])

    visited = [False] * (n + 1)
    visited[1] = True

    parent = [-1] * (n + 1)

    while queue:
        node = queue.popleft()

        for nei in graph[node]:
            if not visited[nei]:
                visited[nei] = True
                parent[nei] = node
                queue.append(nei)

    if not visited[n]:
        print("IMPOSSIBLE")
    else:
        path = []

        node = n
        while node != -1:
            path.append(node)
            node = parent[node]

        path.reverse()

        print(len(path))
        print(*path)

main()
