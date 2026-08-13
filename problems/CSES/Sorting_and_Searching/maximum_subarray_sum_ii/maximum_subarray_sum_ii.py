import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, a, b = map(int, input().split())
    arr = list(map(int, input().split()))

    prefix = [0] * (n + 1)

    for i in range(n):
        prefix[i + 1] = prefix[i] + arr[i]

    queue = deque()
    res = -10**30

    for right in range(a, n + 1):
        new_left = right - a

        while queue and prefix[queue[-1]] >= prefix[new_left]:
            queue.pop()

        queue.append(new_left)

        min_left = right - b

        while queue[0] < min_left:
            queue.popleft()

        res = max(res, prefix[right] - prefix[queue[0]])

    print(res)

main()
