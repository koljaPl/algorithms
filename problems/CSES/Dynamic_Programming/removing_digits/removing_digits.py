import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())

    dp = [0] + [10**9] * n

    for number in range(1, n + 1):
        value = number

        while value > 0:
            digit = value % 10
            value //= 10

            if digit != 0:
                dp[number] = min(
                    dp[number],
                    dp[number - digit] + 1
                )

    print(dp[n])

main()
