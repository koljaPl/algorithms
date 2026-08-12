import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

MOD = 10**9 + 7

def main():
    n = int(input())

    dp = [0] * (n + 1)
    dp[0] = 1

    for total in range(1, n + 1):
        for dice in range(1, 7):
            if total - dice >= 0:
                dp[total] += dp[total - dice]

        dp[total] %= MOD

    print(dp[n])

main()
