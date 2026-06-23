import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

# Russian:
"""
Этот код полностью логически правильный, но изза особености Python (в особенности его скорости)
это решение не пройдет, и как мне кажеться, найти решение на Python которое пройдет тесты будет
весьма проблематично.
"""

# English:
"""
This code is entirely logically correct, but due to a peculiarity of Python (particularly its speed),
this solution will not pass the tests, and I think it will be quite difficult to find a Python solution 
that will pass the tests.
"""

class Fenwick:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, i, value):
        while i <= self.n:
            self.bit[i] += value
            i += i & -i

    def prefix_sum(self, i):
        res = 0

        while i > 0:
            res += self.bit[i]
            i -= i & -i

        return res

def main():
    n = int(input())
    ranges = []
    for i in range(n):
        x, y = map(int, input().split())
        ranges.append((x, y, i))

    ranges.sort(key=lambda x: x[1], reverse=True)
    ranges.sort(key=lambda x: x[0])

    ys = sorted(list(set(r[1] for r in ranges)))
    comp = {y: i + 1 for i, y in enumerate(ys)}

    contains = [0] * n
    contained_by = [0] * n

    bit = Fenwick(len(ys))

    for x, y, idx in reversed(ranges):
        pos = comp[y]
        contains[idx] = bit.prefix_sum(pos)
        bit.add(pos, 1)

    bit = Fenwick(len(ys))
    processed = 0

    for x, y, idx in ranges:
        pos = comp[y]
        contained_by[idx] = processed - bit.prefix_sum(pos - 1)
        bit.add(pos, 1)
        processed += 1

    print(*contains)
    print(*contained_by)

main()
