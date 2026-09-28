import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

# Russian
'''
Решение для этой задачи логически правильное, но изза того что Python не очень быстрый,
легче написать решение для этоц задачи на C++.
'''

# English
'''
The solution to this problem is logically correct, but since Python isn't very fast,
it's easier to write a solution to this problem in C++.
'''

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

def main():
    n, q = map(int, input().split())
    arr = [0] + list(map(int, input().split()))

    queries = []

    for i in range(q):
        l, r = map(int, input().split())
        queries.append((r, l, i))

    queries.sort()

    tree = FenwickTree(n)
    last = {}
    res = [0] * q

    pos = 1

    for r, l, idx in queries:
        while pos <= r:
            x = arr[pos]

            if x in last:
                tree.add(last[x], -1)

            tree.add(pos, 1)
            last[x] = pos

            pos += 1

        res[idx] = tree.range_sum(l, r)

    print('\n'.join(map(str, res)))

main()
