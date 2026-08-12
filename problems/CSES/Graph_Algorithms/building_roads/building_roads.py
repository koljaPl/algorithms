import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    visited = [False] * (n + 1)
    representatives = []

    def dfs(start):
        stack = [start]
        visited[start] = True

        while stack:
            node = stack.pop()

            for nei in graph[node]:
                if not visited[nei]:
                    visited[nei] = True
                    stack.append(nei)

    for city in range(1, n + 1):
        if not visited[city]:
            representatives.append(city)
            dfs(city)

    print(len(representatives) - 1)

    for i in range(1, len(representatives)):
        print(representatives[i - 1], representatives[i])

main()
