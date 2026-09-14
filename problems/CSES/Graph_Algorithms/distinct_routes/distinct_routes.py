import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

class Edge:
    def __init__(self, to, rev, cap, original=False):
        self.to = to
        self.rev = rev
        self.cap = cap
        self.original = original

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]

    def add_edge(u, v):
        forward = Edge(v, len(graph[v]), 1, True)
        backward = Edge(u, len(graph[u]), 0, False)

        graph[u].append(forward)
        graph[v].append(backward)

    for _ in range(m):
        a, b = map(int, input().split())
        add_edge(a - 1, b - 1)

    source = 0
    sink = n - 1

    level = [-1] * n
    ptr = [0] * n

    def bfs():
        level[:] = [-1] * n
        level[source] = 0

        q = deque([source])

        while q:
            u = q.popleft()

            for e in graph[u]:
                if e.cap > 0 and level[e.to] == -1:
                    level[e.to] = level[u] + 1
                    q.append(e.to)

        return level[sink] != -1

    def dfs(u, pushed):
        if u == sink:
            return pushed

        while ptr[u] < len(graph[u]):
            e = graph[u][ptr[u]]

            if e.cap > 0 and level[e.to] == level[u] + 1:
                flow = dfs(e.to, min(pushed, e.cap))

                if flow:
                    e.cap -= flow
                    graph[e.to][e.rev].cap += flow
                    return flow

            ptr[u] += 1

        return 0

    max_flow = 0

    while bfs():
        ptr[:] = [0] * n

        while True:
            pushed = dfs(source, 10**9)

            if not pushed:
                break

            max_flow += pushed

    def find_path():
        parent = [None] * n
        parent[source] = (-1, -1)

        q = deque([source])

        while q and parent[sink] is None:
            u = q.popleft()

            for i, e in enumerate(graph[u]):
                if (
                    e.original
                    and e.cap == 0
                    and parent[e.to] is None
                ):
                    parent[e.to] = (u, i)
                    q.append(e.to)

        path = []

        v = sink

        while v != source:
            u, edge_index = parent[v]

            path.append(v)

            e = graph[u][edge_index]
            e.cap = 1

            v = u

        path.append(source)
        path.reverse()

        return path

    print(max_flow)

    for _ in range(max_flow):
        path = find_path()

        print(len(path))
        print(*(v + 1 for v in path))

main()
