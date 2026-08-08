import sys
from bisect import bisect_left
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())

    projects = []

    for _ in range(n):
        start, end, reward = map(int, input().split())
        projects.append((end, start, reward))

    projects.sort()

    ends = [project[0] for project in projects]

    dp = [0] * (n + 1)

    for i in range(1, n + 1):
        end, start, reward = projects[i - 1]

        compatible_count = bisect_left(ends, start, 0, i - 1)

        skip_current = dp[i - 1]
        take_current = reward + dp[compatible_count]

        dp[i] = max(skip_current, take_current)

    print(dp[n])

main()
