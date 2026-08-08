import sys

input = sys.stdin.readline

def main():
    h, w = map(int, input().split())
    n = max(h, w)

    dp = [[0] * (n + 1) for _ in range(n + 1)]

    for b in range(1, n + 1):
        for a in range(1, b + 1):
            if a == b:
                continue

            best = a * b - 1

            for cut in range(1, a // 2 + 1):
                candidate = (
                    1
                    + dp[cut][b]
                    + dp[a - cut][b]
                )

                if candidate < best:
                    best = candidate

            for cut in range(1, b // 2 + 1):
                first_a = min(a, cut)
                first_b = max(a, cut)

                second = b - cut
                second_a = min(a, second)
                second_b = max(a, second)

                candidate = (
                    1
                    + dp[first_a][first_b]
                    + dp[second_a][second_b]
                )

                if candidate < best:
                    best = candidate

            dp[a][b] = best
            dp[b][a] = best

    print(dp[h][w])

main()
