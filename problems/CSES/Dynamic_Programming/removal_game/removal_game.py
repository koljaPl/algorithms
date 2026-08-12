import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    arr = list(map(int, input().split()))

    dp = arr[:]

    for length in range(2, n + 1):
        for left in range(n - length + 1):
            right = left + length - 1

            take_left = arr[left] - dp[left + 1]
            take_right = arr[right] - dp[left]

            dp[left] = max(take_left, take_right)

    total_sum = sum(arr)
    difference = dp[0]

    first_score = (total_sum + difference) // 2
    print(first_score)

main()
