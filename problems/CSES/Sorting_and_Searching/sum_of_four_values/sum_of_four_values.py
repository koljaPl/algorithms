import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))

    pairs = {}

    for j in range(n):
        for k in range(j + 1, n):
            need = x - a[j] - a[k]

            if need in pairs:
                i1, i2 = pairs[need]
                print(i1 + 1, i2 + 1, j + 1, k + 1)
                return

        for i in range(j):
            pairs[a[i] + a[j]] = (i, j)

    print("IMPOSSIBLE")

main()
