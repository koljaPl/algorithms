import sys
from collections import deque
sys.setrecursionlimit(200000)

input = sys.stdin.readline

# Russian
'''
Решение для этой задачи логически правильное, но изза того что Python не очень быстрый,
легче написать решение для этоц задачи на C++.
'''

# English
'''
The solution to this problem is logically correct, but since Python isn't very fast,
it's easier to write a solution to this problem in C++.
'''

def main():
    n, m = map(int, input().split())

    adj = [[] for _ in range(n)]
    to = []
    cap = []

    def add_edge(u, v, c):
        adj[u].append(len(to))
        to.append(v)
        cap.append(c)

        adj[v].append(len(to))
        to.append(u)
        cap.append(0)

    for _ in range(m):
        u, v, c = map(int, input().split())
        add_edge(u - 1, v - 1, c)

    s = 0
    t = n - 1

    level = [-1] * n
    ptr = [0] * n

    def bfs():
        level[:] = [-1] * n
        level[s] = 0

        q = deque([s])

        while q:
            u = q.popleft()

            for e in adj[u]:
                if cap[e] == 0:
                    continue

                v = to[e]

                if level[v] != -1:
                    continue

                level[v] = level[u] + 1
                q.append(v)

        return level[t] != -1

    def dfs(u, pushed):
        if u == t:
            return pushed

        while ptr[u] < len(adj[u]):
            e = adj[u][ptr[u]]
            v = to[e]

            if cap[e] > 0 and level[v] == level[u] + 1:
                flow = dfs(v, min(pushed, cap[e]))

                if flow:
                    cap[e] -= flow
                    cap[e ^ 1] += flow
                    return flow

            ptr[u] += 1

        return 0

    max_flow = 0
    INF = 10 ** 18

    while bfs():
        ptr[:] = [0] * n

        while True:
            pushed = dfs(s, INF)

            if pushed == 0:
                break

            max_flow += pushed

    print(max_flow)

main()
