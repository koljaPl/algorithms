import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    h = [0] + list(map(int, input().split()))

    LOG = (n + 1).bit_length()
    INF = n + 1

    up = [[INF] * (n + 2) for _ in range(LOG)]
    stack = []

    for i in range(n, 0, -1):
        while stack and h[stack[-1]] <= h[i]:
            stack.pop()

        if stack:
            up[0][i] = stack[-1]

        stack.append(i)

    for k in range(1, LOG):
        prev = up[k - 1]
        curr = up[k]

        for i in range(1, n + 1):
            curr[i] = prev[prev[i]]

    for _ in range(q):
        a, b = map(int, input().split())

        pos = a
        res = 1

        for k in range(LOG - 1, -1, -1):
            nxt = up[k][pos]

            if nxt <= b:
                pos = nxt
                res += 1 << k

        print(res)

main()
