import sys
from collections import Counter
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    MOD = 10**9 + 7
    n = int(input())
    list_x = list(map(int, input().split()))

    counts = Counter(list_x)

    res = 1
    for count in counts.values():
        res = (res * (count + 1)) % MOD

    print((res - 1 + MOD) % MOD)

main()
