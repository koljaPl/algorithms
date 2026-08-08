import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

MOD = 10**9 + 7

# Russian
'''
Решение для этой задачи логически правильное, но изза того что Python не очень быстрый,
легче написать решение для этоц задачи на C++.
'''

# English
'''
The solution to this problem is logically correct, but since Python isn't very fast,
it's easier to write a solution to this problem in C++.
'''

def main():
    n, target = map(int, input().split())
    coins = list(map(int, input().split()))

    dp = [0] * (target + 1)
    dp[0] = 1

    for curr_sum in range(1, target + 1):
        for coin in coins:
            if coin <= curr_sum:
                dp[curr_sum] += dp[curr_sum - coin]

                if dp[curr_sum] > MOD:
                    dp[curr_sum] %= MOD

    print(dp[target])

main()
