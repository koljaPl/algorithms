import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    MOD = 10 ** 9 + 7

    n = int(input())
    grid = [input().strip() for _ in range(n)]

    dp = [0] * n
    dp[0] = 1

    for i in range(n):
        for j in range(n):
            if grid[i][j] == '*':
                dp[j] = 0
            elif j > 0:
                dp[j] = (dp[j] + dp[j - 1]) % MOD

    print(dp[n - 1])

main()
