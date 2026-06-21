import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, i, value):
        while i <= self.n:
            self.bit[i] += value
            i += i & -i

    def prefix_sum(self, i):
        prefix_sum = 0

        while i > 0:
            prefix_sum += self.bit[i]
            i -= i & -i

        return prefix_sum

    def range_sum(self, start, end):
        return self.prefix_sum(end) - self.prefix_sum(start - 1)

    def get_index(self, k):
        pos = 0
        step = 1 << 18

        while step:
            nxt = pos + step
            if nxt <= self.n and self.bit[nxt] < k:
                k -= self.bit[nxt]
                pos = nxt
            step >>= 1

        return pos + 1

def main():
    n, k = map(int, input().split())

    fw = FenwickTree(n)

    for i in range(1, n + 1):
        fw.add(i, 1)

    curr = 0
    alive = n
    res = []

    while alive > 0:
        curr = (curr + k) % alive

        index = fw.get_index(curr + 1)

        res.append(index)

        fw.add(index, -1)
        alive -= 1

    print(*res)

main()
