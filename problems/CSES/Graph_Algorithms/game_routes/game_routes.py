import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    MOD = 10**9 + 7

    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]
    indegree = [0] * n

    for _ in range(m):
        a, b = map(int, input().split())

        graph[a - 1].append(b - 1)
        indegree[b - 1] += 1

    queue = deque()

    for v in range(n):
        if indegree[v] == 0:
            queue.append(v)

    dp = [0] * n
    dp[0] = 1

    while queue:
        v = queue.popleft()

        for u in graph[v]:
            dp[u] = (dp[u] + dp[v]) % MOD

            indegree[u] -= 1
            if indegree[u] == 0:
                queue.append(u)

    print(dp[n - 1])

main()
