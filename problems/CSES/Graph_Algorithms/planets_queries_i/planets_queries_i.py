import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    t = list(map(int, input().split()))

    LOG = 31

    up = [[0] * n for _ in range(LOG)]

    for v in range(n):
        up[0][v] = t[v] - 1

    for j in range(1, LOG):
        for v in range(n):
            up[j][v] = up[j - 1][up[j - 1][v]]

    for _ in range(q):
        x, k = map(int, input().split())
        x -= 1

        for j in range(LOG):
            if k & (1 << j):
                x = up[j][x]

        print(x + 1)

main()
