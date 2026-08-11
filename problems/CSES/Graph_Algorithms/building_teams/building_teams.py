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

    team = [0] * (n + 1)

    for start in range(1, n + 1):
        if team[start] != 0:
            continue

        team[start] = 1
        q = deque([start])

        while q:
            node = q.popleft()

            for nei in graph[node]:
                if team[nei] == 0:
                    team[nei] = 3 - team[node]
                    q.append(nei)

                elif team[nei] == team[node]:
                    print("IMPOSSIBLE")
                    exit()

    print(*team[1:])

main()
