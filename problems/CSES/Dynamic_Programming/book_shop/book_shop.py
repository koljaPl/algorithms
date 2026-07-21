import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, money = map(int, input().split())
    prices = list(map(int, input().split()))
    pages = list(map(int, input().split()))

    dp = [0] * (money + 1)

    for i in range(0, n):
        curr_price = prices[i]
        curr_pages = pages[i]

        for x in range(money, curr_price - 1, -1):
            dp[x] = max(dp[x],
                        dp[x - curr_price] + curr_pages)

    print(dp[money])

main()
