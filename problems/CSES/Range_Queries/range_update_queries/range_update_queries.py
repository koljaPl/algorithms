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

    def query(self, idx):
        result = 0

        while idx > 0:
            result += self.bit[idx]
            idx -= idx & -idx

        return result

def main():
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))

    bit = FenwickTree(n)

    previous = 0
    for i in range(1, n + 1):
        bit.add(i, arr[i - 1] - previous)
        previous = arr[i - 1]

    for _ in range(q):
        query = list(map(int, input().split()))

        if query[0] == 1:
            _, a, b, u = query
            bit.add(a, u)

            if b + 1 <= n:
                bit.add(b + 1, -u)
        else:
            _, k = query

            print(bit.query(k))

main()
