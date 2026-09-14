import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

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

    def subtract(self, i, value):
        while i <= self.n:
            self.bit[i] -= value
            i += i & -i

    def prefix_sum(self, i):
        res = 0

        while i > 0:
            res += self.bit[i]
            i -= i & -i

        return res

    def range_sum(self, start, end):
        return self.prefix_sum(end) - self.prefix_sum(start - 1)

def main():
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))

    bit = FenwickTree(n)

    for i, x in enumerate(arr, 1):
        bit.add(i, x)

    for _ in range(q):
        type, a, b = map(int, input().split())

        if type == 1:
            delta = b - arr[a - 1]
            arr[a - 1] = b
            bit.add(a, delta)
        else:
            print(bit.range_sum(a, b))

main()