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
    x = list(map(int, input().split()))

    elements = sorted((x[i], i + 1) for i in range(n))
    
    events = []
    for qi in range(q):
        a, b, c, d = map(int, input().split())

        events.append((d, qi, 1, a, b))
        events.append((c - 1, qi, -1, a, b))

    events.sort()

    fw = FenwickTree(n)
    res = [0] * q

    j = 0

    for threshold, qi, sign, a, b in events:
        while j < n and elements[j][0] <= threshold:
            _, pos = elements[j]
            fw.add(pos, 1)
            j += 1

        res[qi] += sign * fw.range_sum(a, b)

    print("\n".join(map(str, res)))

main()
