import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def bfs(start, graph):
    n = len(graph)
    visited = [False] * n

    queue = deque([start])
    visited[start] = True

    while queue:
        u = queue.popleft()

        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                queue.append(v)

    return visited

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]
    reverse_graph = [[] for _ in range(n)]

    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        graph[a].append(b)
        reverse_graph[b].append(a)

    visited = bfs(0, graph)

    for v in range(n):
        if not visited[v]:
            print("NO")
            print(1, v + 1)
            return

    visited_reverse = bfs(0, reverse_graph)

    for v in range(n):
        if not visited_reverse[v]:
            print("NO")
            print(v + 1, 1)
            return

    print("YES")

main()
