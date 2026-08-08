import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    coins = [int(x) for x in input().split()]

    dp = 1

    for coin in coins:
        dp |= (dp << coin)

    res = []

    for s in range(1, sum(coins) + 1):
        if (dp >> s) & 1:
            res.append(s)

    print(len(res))
    print(*res)

main()
