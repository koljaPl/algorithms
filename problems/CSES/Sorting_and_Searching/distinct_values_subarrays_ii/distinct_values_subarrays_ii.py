import sys
from collections import defaultdict
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    count = defaultdict(int)

    left = 0
    distinct = 0
    res = 0

    for right in range(n):
        if count[arr[right]] == 0:
            distinct += 1

        count[arr[right]] += 1

        while distinct > k:
            count[arr[left]] -= 1

            if count[arr[left]] == 0:
                distinct -= 1

            left += 1

        res += right - left + 1

    print(res)

main()
