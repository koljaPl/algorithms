import sys
sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a - 1].append(b - 1)

    res = []
    visited = set()
    cycle = set()

    def dfs(course):
        if course in cycle:
            return False

        if course in visited:
            return True

        cycle.add(course)

        for nxt in graph[course]:
            if not dfs(nxt):
                return False

        cycle.remove(course)
        visited.add(course)

        res.append(course)

        return True

    for i in range(n):
        if i not in visited:
            if not dfs(i):
                print("IMPOSSIBLE")
                return

    res.reverse()

    print(*(x + 1 for x in res))

main()
