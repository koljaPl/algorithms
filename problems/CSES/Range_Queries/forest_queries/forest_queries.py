import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    pref = [[0] * (n + 1) for _ in range(n + 1)]

    for y in range(1, n + 1):
        row = input().strip()

        for x in range(1, n + 1):
            tree = 1 if row[x - 1] == "*" else 0
            pref[y][x] = pref[y - 1][x] + pref[y][x - 1] - pref[y - 1][x - 1] + tree

    for _ in range(q):
        y1, x1, y2, x2 = map(int, input().split())
        print(pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] + pref[y1 - 1][x1 - 1])

main()
