import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())

    q = deque(range(1, n + 1))
    res = []

    while q:
        q.append(q.popleft())
        res.append(q.popleft())

    print(*res)

main()
