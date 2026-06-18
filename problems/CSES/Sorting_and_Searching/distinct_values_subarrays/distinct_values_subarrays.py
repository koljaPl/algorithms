import sys
from collections import defaultdict
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    list_x = list(map(int, input().split()))

    count = defaultdict(int)
    left, res = 0, 0

    for i in range(n):
        count[list_x[i]] += 1

        while count[list_x[i]] > 1:
            count[list_x[left]] -= 1
            left += 1

        res += i - left + 1

    print(res)

main()
