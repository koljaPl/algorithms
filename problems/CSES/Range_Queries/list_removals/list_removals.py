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
        prefix_sum = 0

        while i > 0:
            prefix_sum += self.bit[i]
            i -= i & -i

        return prefix_sum

    def range_sum(self, start, end):
        return self.prefix_sum(end) - self.prefix_sum(start - 1)

    def kth(self, k):
        pos = 0
        bit = 1 << (self.n.bit_length() - 1)

        while bit:
            nxt = pos + bit

            if nxt <= self.n and self.bit[nxt] < k:
                pos = nxt
                k -= self.bit[nxt]

            bit >>= 1

        return pos + 1

def main():
    n = int(input())

    x = [0] + list(map(int, input().split()))
    positions = list(map(int, input().split()))

    fw = FenwickTree(n)

    for i in range(1, n + 1):
        fw.add(i, 1)

    res = []

    for p in positions:
        pos = fw.kth(p)
        res.append(str(x[pos]))

        fw.add(pos, -1)

    print(*res)

main()
