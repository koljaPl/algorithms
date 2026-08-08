import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    MOD = 10**9 + 7
    n = int(input())

    total_sum = n * (n + 1) // 2

    if (total_sum % 2 != 0):
        print(0)
        return

    target = total_sum // 2

    dp = [0] * (target + 1)
    dp[0] = 1

    for x in range(1, n):
        for curr_sum in range(target, x - 1, -1):
            dp[curr_sum] += dp[curr_sum - x]

            if (dp[curr_sum] >= MOD):
                dp[curr_sum] -= MOD

    print(dp[target])

main()
