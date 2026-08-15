import sys
import heapq
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

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
    n, m, q = map(int, input().split())

    INF = 10 ** 20

    dist = [[INF] * n for _ in range(n)]

    for i in range(n):
        dist[i][i] = 0

    # Дороги
    for _ in range(m):
        a, b, c = map(int, input().split())

        a -= 1
        b -= 1

        dist[a][b] = min(dist[a][b], c)
        dist[b][a] = min(dist[b][a], c)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                )

    for _ in range(q):
        a, b = map(int, input().split())

        a -= 1
        b -= 1

        if dist[a][b] == INF:
            print(-1)
        else:
            print(dist[a][b])

main()
