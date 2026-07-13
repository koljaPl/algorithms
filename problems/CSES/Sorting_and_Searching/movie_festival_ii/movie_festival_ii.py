import sys
from bisect import bisect_right
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
        index = 0
        step = 1 << (self.n.bit_length() - 1)

        while step:
            next_index = index + step

            if next_index <= self.n and self.bit[next_index] < k:
                index = next_index
                k -= self.bit[next_index]

            step >>= 1

        return index + 1

def main():
    n, k = map(int, input().split())
    movies = []
    times = [0]

    for _ in range(n):
        start, finish = map(int, input().split())
        movies.append((start, finish))
        times.append(finish)

    movies.sort(key=lambda movie: movie[1])

    times = sorted(set(times))

    fenwick = FenwickTree(len(times))

    zero_index = 1
    fenwick.add(zero_index, k)

    res = 0

    for start, finish in movies:
        position = bisect_right(times, start)

        available_count = fenwick.prefix_sum(position)

        if available_count == 0:
            continue

        member_index = fenwick.kth(available_count)

        fenwick.add(member_index, -1)

        finish_index = bisect_right(times, finish)
        fenwick.add(finish_index, 1)

        res += 1

    print(res)

main()
