import sys
from bisect import bisect_right

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    tickets = sorted(list(map(int, input().split())))
    customers = list(map(int, input().split()))

    parents = list(range(n))

    def find(x):
        if x < 0:
            return -1

        if parents[x] == x:
            return x

        parents[x] = find(parents[x])
        return parents[x]

    for money in customers:

        pos = bisect_right(tickets, money) - 1

        pos = find(pos)

        if pos == -1:
            print(-1)
            continue

        print(tickets[pos])

        parents[pos] = find(pos - 1)

main()
