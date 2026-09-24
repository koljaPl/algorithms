import sys
from bisect import bisect_left, bisect_right
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

def main():
    n, q = map(int, input().split())
    salary = list(map(int, input().split()))

    queries = []
    coords = salary[:]

    for _ in range(q):
        t, a, b = input().split()
        a = int(a)
        b = int(b)

        queries.append((t, a, b))

        if t == "!":
            coords.append(b)

    coords = sorted(set(coords))

    def idx(x):
        return bisect_left(coords, x) + 1

    ft = FenwickTree(len(coords))

    for x in salary:
        ft.add(idx(x), 1)

    for t, a, b in queries:
        if t == "!":
            k = a - 1
            new_salary = b

            ft.add(idx(salary[k]), -1)

            salary[k] = new_salary
            ft.add(idx(new_salary), 1)
        else:
            right = bisect_right(coords, b)
            left = bisect_left(coords, a)

            print(ft.prefix_sum(right) - ft.prefix_sum(left))

main()
