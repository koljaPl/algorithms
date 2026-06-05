import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    t = int(input())

    for _ in range(t):
        n, a, b = map(int, input().split())

        if a + b > n or ((a == 0) != (b == 0)):
            print("NO")
            continue

        draws = n - a - b

        p1 = list(range(1, n + 1))
        p2 = list(range(1, draws + 1)) + list(range(draws + a + 1, n + 1)) + list(range(draws + 1, draws + a + 1))

        print("YES")
        print(*p1)
        print(*p2)

main()
