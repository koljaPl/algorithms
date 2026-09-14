import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

class Edge:
    def __init__(self, to, rev, cap):
        self.to = to
        self.rev = rev
        self.cap = cap

def add_edge(graph, u, v, cap):
    graph[u].append(Edge(v, len(graph[v]), cap))
    graph[v].append(Edge(u, len(graph[u]) - 1, 0))

def bfs(graph, s, t, level):
    q = deque([s])
    level[s] = 0

    while q:
        u = q.popleft()

        for e in graph[u]:
            if e.cap > 0 and level[e.to] == -1:
                level[e.to] = level[u] + 1
                q.append(e.to)

    return level[t] != -1

def dfs(graph, u, t, pushed, level, ptr):
    if pushed == 0:
        return 0

    if u == t:
        return pushed

    while ptr[u] < len(graph[u]):
        e = graph[u][ptr[u]]

        if e.cap > 0 and level[e.to] == level[u] + 1:
            flow = dfs(
                graph,
                e.to,
                t,
                min(pushed, e.cap),
                level,
                ptr
            )

            if flow:
                e.cap -= flow
                graph[e.to][e.rev].cap += flow
                return flow

        ptr[u] += 1

    return 0

def max_flow(graph, s, t):
    n = len(graph)
    flow = 0

    while True:
        level = [-1] * n

        if not bfs(graph, s, t, level):
            break

        ptr = [0] * n

        while True:
            pushed = dfs(
                graph,
                s,
                t,
                10**18,
                level,
                ptr
            )

            if pushed == 0:
                break

            flow += pushed

    return flow

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]
    edges = []

    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        edges.append((a, b))

        add_edge(graph, a, b, 1)
        add_edge(graph, b, a, 1)

    s = 0
    t = n - 1

    max_flow(graph, s, t)

    visited = [False] * n
    visited[s] = True

    q = deque([s])

    while q:
        u = q.popleft()

        for e in graph[u]:
            if e.cap > 0 and not visited[e.to]:
                visited[e.to] = True
                q.append(e.to)

    res = []
    for a, b in edges:
        if visited[a] != visited[b]:
            res.append((a + 1, b + 1))

    print(len(res))

    for a, b in res:
        print(a, b)

main()
