import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m, k = map(int, input().split())

    adj = [[] for _ in range(n)]

    for _ in range(k):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        adj[a].append(b)

    match = [-1] * m

    def dfs(boy):
        if used[boy]:
            return False

        used[boy] = True

        for girl in adj[boy]:
            if match[girl] == -1 or dfs(match[girl]):
                match[girl] = boy
                return True

        return False

    res = 0

    for boy in range(n):
        used = [False] * n

        if dfs(boy):
            res += 1

    print(res)

    for girl in range(m):
        if match[girl] != -1:
            print(match[girl] + 1, girl + 1)

main()
