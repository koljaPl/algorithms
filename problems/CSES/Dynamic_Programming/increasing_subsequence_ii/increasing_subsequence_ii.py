import sys
from bisect import bisect_left
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

MOD = 10 ** 9 + 7

class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    # Add function (also known as update),
    # and ofcourse you can use it like -value for subtract from bit, but I think it's not that cool
    def add(self, i, value):
        while i <= self.n:
            self.bit[i] += value
            i += i & -i

    def query(self, i):
        res = 0

        while i > 0:
            res = (res + self.bit[i]) % MOD
            i -= i & -i

        return res

def main():
    n = int(input())
    arr = list(map(int, input().split()))

    values = sorted(set(arr))

    fenwick = FenwickTree(len(values))
    res = 0

    for value in arr:
        position = bisect_left(values, value) + 1

        curr = 1 + fenwick.query(position - 1)
        curr %= MOD

        fenwick.add(position, curr)

        res = (res + curr) % MOD

    print(res)

main()
