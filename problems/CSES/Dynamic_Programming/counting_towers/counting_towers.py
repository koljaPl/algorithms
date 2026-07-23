import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main_v1():
    MOD = 10**9 + 7
    MAX_N = 1_000_000
    t = int(input())

    dp = [[0, 0] for _ in range(MAX_N + 1)]

    dp[1][0] = 1;
    dp[1][1] = 1;

    for i in range(2, MAX_N + 1):
        dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD
        dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % MOD

    for _ in range(t):
        n = int(input())

        print((dp[n][0] + dp[n][1]) % MOD)

def main():
    MOD = 10 ** 9 + 7
    MAX_N = 1_000_000
    t = int(input())

    towers = [0] * (MAX_N + 1)

    towers[1] = 2
    towers[2] = 8

    for i in range(3, MAX_N + 1):
        towers[i] = (6 * towers[i - 1] + (MOD - 7) * towers[i - 2]) % MOD

    for _ in range(t):
        n = int(input())

        print(towers[n])

main()
