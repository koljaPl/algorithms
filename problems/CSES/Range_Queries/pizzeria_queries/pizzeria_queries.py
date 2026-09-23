import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

INF = 10**30

class IterativeSegmentTree:
    def __init__(self, arr, merge, identity):
        self.n = len(arr)
        self.size = 1
        while self.size < self.n:
            self.size *= 2

        self.tree = [identity] * (2 * self.size)

        self.merge = merge
        self.identity = identity

        for i in range(self.n):
            self.tree[self.size + i] = arr[i]

        for i in range(self.size - 1, 0, -1):
            self.tree[i] = self.merge(
                self.tree[i * 2],
                self.tree[i * 2 + 1]
            )

    def set(self, idx, value):
        pos = self.size + idx
        self.tree[pos] = value

        pos //= 2
        while pos >= 1:
            self.tree[pos] = self.merge(
                self.tree[2 * pos],
                self.tree[2 * pos + 1]
            )
            pos //= 2

    def query(self, left, right):
        left += self.size
        right += self.size + 1

        res_left = self.identity
        res_right = self.identity

        while left < right:
            if left % 2 == 1:
                res_left = self.merge(res_left, self.tree[left])
                left += 1
            if right % 2 == 1:
                right -= 1
                res_right = self.merge(self.tree[right], res_right)

            left //= 2
            right //= 2

        return self.merge(res_left, res_right)

def main():
    n, q = map(int, input().split())
    p = list(map(int, input().split()))

    left = [p[i] - (i + 1) for i in range(n)]
    right = [p[i] + (i + 1) for i in range(n)]

    left_tree = IterativeSegmentTree(left, min, INF)
    right_tree = IterativeSegmentTree(right, min, INF)

    for _ in range(q):
        query = list(map(int, input().split()))

        if query[0] == 1:
            _, k, x = query
            k -= 1

            left_tree.set(k, x - (k + 1))
            right_tree.set(k, x + (k + 1))
        else:
            _, k = query
            k -= 1

            from_left = left_tree.query(0, k) + (k + 1)
            from_right = right_tree.query(k, n - 1) - (k + 1)

            print(min(from_left, from_right))

main()
