import sys
from bisect import bisect_left
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())

    arr = list(map(int, input().split()))

    tails = []

    for x in arr:
        pos = bisect_left(tails, x)

        if pos == len(tails):
            tails.append(x)
        else:
            tails[pos] = x

    print(len(tails))

main()
