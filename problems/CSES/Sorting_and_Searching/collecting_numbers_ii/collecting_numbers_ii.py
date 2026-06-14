import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    list_x = list(map(int, input().split()))

    pos = [0] * (n + 1)

    for i, x in enumerate(list_x):
        pos[x] = i

    res = 1
    for i in range(2, n + 1):
        if pos[i] < pos[i - 1]:
            res += 1

    for _ in range(m):
        l, r = map(int, input().split())
        l -= 1
        r -= 1

        x = list_x[l]
        y = list_x[r]

        pairs = set()

        for v in (x, y):
            if v > 1:
                pairs.add((v - 1, v))
            if v < n:
                pairs.add((v, v + 1))

        for u, v in pairs:
            if pos[v] < pos[u]:
                res -= 1

        list_x[l], list_x[r] = list_x[r], list_x[l]
        pos[x], pos[y] = pos[y], pos[x]

        for u, v in pairs:
            if pos[v] < pos[u]:
                res += 1

        print(res)

main()
