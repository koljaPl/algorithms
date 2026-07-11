import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    grid = [input().strip() for _ in range(n)]

    letters = "ABCD"

    res = [[''] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            for c in letters:
                if c == grid[i][j]:
                    continue

                if i > 0 and res[i - 1][j] == c:
                    continue

                if j > 0 and res[i][j - 1] == c:
                    continue

                res[i][j] = c
                break

    for row in res:
        print("".join(row))

main()
