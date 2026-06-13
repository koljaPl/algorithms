import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    coins = sorted(list(map(int, input().split())))

    res = 1

    for coin in coins:
        if coin > res:
            break
        res += coin

    print(res)

main()
