import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, target = map(int, input().split())
    coins = list(map(int, input().split()))

    INF = target + 1

    dp = [INF] * (target + 1)
    dp[0] = 0

    for coin in coins:
        for curr_sum in range(coin, target + 1):
            candidate = dp[curr_sum - coin] + 1

            if candidate < dp[curr_sum]:
                dp[curr_sum] = candidate

    print(-1 if dp[target] == INF else dp[target])

main()
